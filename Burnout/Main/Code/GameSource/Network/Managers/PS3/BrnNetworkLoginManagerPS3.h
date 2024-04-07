#include "Network/Managers/BrnNetworkLoginManagerBase.h"

namespace BrnNetwork 
{
	class LoginManagerPS3 : LoginManagerBase 
	{
	public:
		enum EPlatformSpecificSubState : int
		{
			E_PLATFORM_SPECIFIC_SUBSTATE_SIGN_IN_TO_NP = 0x0,
			E_PLATFORM_SPECIFIC_SUBSTATE_ACCOUNT_SIGN_IN = 0x1,
			E_PLATFORM_SPECIFIC_SUBSTATE_SHOW_CHAT_POPUP = 0x2,
			E_PLATFORM_SPECIFIC_SUBSTATE_COUNT = 0x3,
		};

		LoginManagerPS3();

		void Construct(BrnNetworkModule* lpNetworkModule);

		bool Prepare();

		bool Release();

		void Destruct();

		virtual void Start(ESignInType leSignInType);

		virtual void Disconnected();

	protected:
		virtual void PlatformSpecificUpdate(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput);

		virtual void GetUserNameAndPassword(char *, char *);

	private:
		EPlatformSpecificSubState mePlatformSpecificSubState;

		bool mbHaveShownChatPopup;

		void StartDirtySockSignIn();

		virtual void ShowChatRestrictionPopup();

		void UpdateSignInToNP();

		void UpdateAccountSignIn();

		void UpdateShowChatPopup(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput);
	};
}