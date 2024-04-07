#include "Network/Managers/BrnNetworkLoginManagerBase.h"

namespace BrnNetwork 
{
	void LoginManagerBase::Construct(BrnNetwork::BrnNetworkModule *lpNetworkModule)
	{
		BrnNetwork::BrnNetworkManager *mpNetworkManager;

		if (!lpNetworkModule)
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0,
				"lpNetworkModule");
		}
		this->mpNetworkModule = lpNetworkModule;
		mpNetworkManager = BrnNetworkModule::GetNetworkManager(lpNetworkModule);
		this->mpNetworkManager = mpNetworkManager;
		if (!mpNetworkManager)
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0,
				"mpNetworkManager");
		}
		this->meSignInState = E_SIGN_IN_STATE_COUNT;
		this->meSubState = E_SUBSTATE_COUNT;
		this->meSignInType = E_SIGN_IN_TYPE_COUNT;
		this->meCompletedSignInType = E_SIGN_IN_TYPE_COUNT;
		this->mpTOS = nullptr;
	}

	void LoginManagerBase::Disconnected()
	{
		CgsUnicode::CgsUtf8* mpTOS;

		mpTOS = this->mpTOS;
		this->meSignInState = E_SIGN_IN_STATE_COUNT;
		this->meSignInType = E_SIGN_IN_TYPE_COUNT;
		this->meSubState = E_SUBSTATE_COUNT;
		this->meCompletedSignInType = E_SIGN_IN_TYPE_COUNT;
		this->mbAgreeShare1 = false;
		this->mbAgreeShare2 = false;
		if (mpTOS)
		{
			CgsNetwork::ServerInterfaceDirtySock::MemFree(mpTOS, 0, 0);
			this->mpTOS = nullptr;
		}
	}

	void LoginManagerBase::AnswerSignIn(bool lbSuccess)
	{
		if (this->meSignInState)
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0,
				"meSignInState == E_SIGN_IN_STATE_SIGNING_IN");
		}
		this->meSignInState = (ESignInState)(!lbSuccess + 1);
	}
	
	void LoginManagerBase::Start(ESignInType leSignInType)
	{
		ESignInType meSignInType = this->meSignInType;
		if (meSignInType == E_SIGN_IN_TYPE_SILENT || meSignInType == E_SIGN_IN_TYPE_COUNT)
		{
			this->meSignInType = leSignInType;
		}

		ESubState meSubState = this->meSubState;
		if (meSubState >= E_SUBSTATE_DONE) 
		{
			// we good
			return; 
		}

		// 0x38D0 is most likely a pointer to the server interface
		if (CgsNetwork::ServerInterfaceConnection::IsLoggedIn(*this->mpNetworkManager->??)) // 0x38D0 + 4
		{
			if (CgsNetwork::ServerInterfaceDirtySock::IsSuspended(this->mpNetworkManager->??)) // 0x38D0
			{
				this->meSubState = E_SUBSTATE_RESUMING_SERVER_INTERFACE;
				SuspensionManager::Resume(this->mpNetworkManager->mpSuspensionManager, &ResumeCompleteCallback, this);
			}
			else
			{
				Finished(true);
			}
		}
		else
		{
			this->meSubState = E_SUBSTATE_PLATFORM_SPECIFIC_UPDATE;
		}
	}

	void LoginManagerBase::ShowChatRestrictionPopup()
	{
		this->meSignInState = E_SIGN_IN_STATE_COUNT;
		this->meSubState = E_SUBSTATE_DONE;
		this->meCompletedSignInType = this->meSignInType;
		this->meSignInType = E_SIGN_IN_TYPE_COUNT;
	}

	void LoginManagerBase::Finished(bool lbSuccess)
	{
		if (!lbSuccess) 
		{
			CgsNetwork::ServerInterfaceConnection::DisconnectFromServer(*this->mpNetworkManager->??); // 0x38EC, could be 0x38D0 + 1C?
		}

		ESignInType eSignInType = this->meSignInType;
		
		this->meSignInState = E_SIGN_IN_STATE_COUNT;
		this->meSubState = E_SUBSTATE_DONE;
		this->meCompletedSignInType = eSignInType;
		this->meSignInType = E_SIGN_IN_TYPE_COUNT;
	}

}