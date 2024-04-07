#include "Fonts/CgsUnicode.h"

namespace BrnNetwork 
{
	class BrnNetworkModule;
	class BrnNetworkManager;

	class LoginManagerBase 
	{

		enum ESignInType : int
		{
			E_SIGN_IN_TYPE_NORMAL = 0x0,
			E_SIGN_IN_TYPE_SILENT = 0x1,
			E_SIGN_IN_TYPE_FREE_BURN_LOBBY = 0x2,
			E_SIGN_IN_TYPE_COUNT = 0x3,
		};

		enum ESignInState : int
		{
			E_SIGN_IN_STATE_SIGNING_IN = 0x0,
			E_SIGN_IN_STATE_SUCCESS = 0x1,
			E_SIGN_IN_STATE_FAILED = 0x2,
			E_SIGN_IN_STATE_COUNT = 0x3,
		};

		enum ESubState : int
		{
			E_SUBSTATE_PLATFORM_SPECIFIC_UPDATE = 0x0,
			E_SUBSTATE_CONNECTING_ONLINE = 0x1,
			E_SUBSTATE_CONNECTING_DS = 0x2,
			E_SUBSTATE_LOGGING_IN = 0x3,
			E_SUBSTATE_DOWNLOADING_TOS = 0x4,
			E_SUBSTATE_GET_CONFIGURATION_DATA = 0x5,
			E_SUBSTATE_WAITING_FOR_PLAYER_ID = 0x6,
			E_SUBSTATE_CONNECTING_TELEMETRY = 0x7,
			E_SUBSTATE_DOWNLOADING_SCOREBOARD_HEADERS = 0x8,
			E_SUBSTATE_WAITING_SELECTION = 0x9,
			E_SUBSTATE_RESUMING_SERVER_INTERFACE = 0xA,
			E_SUBSTATE_LOAD_SETTINGS = 0xB,
			E_SUBSTATE_PING_REGIONS = 0xC,
			E_SUBSTATE_NO_AGREEMENT = 0xD,
			E_SUBSTATE_DONE = 0xE,
			E_SUBSTATE_COUNT = 0xF,
		};

	public:
		LoginManagerBase();
		
		void Construct(BrnNetworkModule *lpNetworkModule);

		bool Prepare();

		bool Release();

		void Destruct();

		bool Update(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput);

		virtual void Start(ESignInType leSignInType);

		virtual void Disconnected();

		void AnswerCreateAccount(bool lbAgree);

		void AnswerShareInfo(bool lbAgree1, bool lbAgree2);

		void AnswerOpenUsAccount(bool lbAgree);

		void AnswerAgreeTOS(bool lbAgree);

		void AnswerNoAgreement(bool lbRestart);

		void AnswerSignIn(bool lbSuccess);

		void AnswerChatRestricted(bool lbSuccess);

		void CancelLogin();

		bool IsSigningIn() const;

		ESignInType GetSignInType() const;

		void FinishedWithTOS();

		ESignInType GetCompletedSignInType() const;

	protected:
		BrnNetworkManager* mpNetworkManager;

		BrnNetworkModule* mpNetworkModule;

		ESubState meSubState;

		ESignInState meSignInState;

		ESignInType meSignInType;

		ESignInType meCompletedSignInType;
	
		virtual void PlatformSpecificUpdate(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput);

		virtual void GetUserNameAndPassword(char* lacUserName, char* lacPassword);

		void Finished(bool lbSuccess);

		void ShowSignInGui();

	private:
		bool mbAgreeShare1;
		bool mbAgreeShare2;

		CgsUnicode::CgsUtf8* mpTOS;

		void LogInToServer();

		void PrepareDownloadingTOS();

		void PrepareDownloadingNews();

		void PrepareConnectTelemetry() 
		{
			using namespace CgsDev::Message;
		}

		void PrepareDownloadingScoreboardHeadings();

		void PrepareLoadSettings();

		void PreparePingRegions();

		virtual void ShowChatRestrictionPopup();

		void SetTelemetryCountryList();

		void SendUPnPTelemetry() 
		{
			using namespace CgsDev::Message;
		}

		void UpdateConnectingOnline();

		void UpdateConnectingDS() 
		{
			using namespace CgsDev::Message;
		}

		void UpdateLoggingIn();

		void UpdateDownloadingTOS();

		void UpdateGetConfigurationData();

		void UpdateWaitingForPlayerID();

		void UpdateConnectingTelemetry();

		void UpdateResumingServerInterface();

		void UpdateDownloadingScoreboardHeadings();

		void UpdateLoadSettings();

		void UpdatePingRegions();

		void ResumeCompleteCallback(bool lbSuccess, void* lpUserData);
	};
}