#include "Fonts/CgsUnicode.h"

namespace BrnNetwork 
{
	class BrnNetworkModule;
	class BrnNetworkManager;

	class LoginManagerBase 
	{
	public:
		enum ESignInType : int
		{
			E_SIGN_IN_TYPE_NORMAL = 0x0,
			E_SIGN_IN_TYPE_SILENT = 0x1,
			E_SIGN_IN_TYPE_FREE_BURN_LOBBY = 0x2,
			E_SIGN_IN_TYPE_COUNT = 0x3,
		};

		void Construct(BrnNetwork::BrnNetworkModule *lpNetworkModule);
		bool Prepare();
		bool Release();
		void Destruct();

		bool Update(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput);

		void Start(ESignInType leSignInType);

		void Disconnected();

		void AnswerSignIn(bool lbSuccess);

	protected:
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

		enum ESignInState : int
		{
			E_SIGN_IN_STATE_SIGNING_IN = 0x0,
			E_SIGN_IN_STATE_SUCCESS = 0x1,
			E_SIGN_IN_STATE_FAILED = 0x2,
			E_SIGN_IN_STATE_COUNT = 0x3,
		};

		BrnNetworkManager* mpNetworkManager;
		BrnNetworkModule* mpNetworkModule;

		ESubState meSubState;
		ESignInState meSignInState;

		ESignInType meSignInType;
		ESignInType meCompletedSignInType;


		void Finished(bool lbSuccess);

	private:
		bool mbAgreeShare1;
		bool mbAgreeShare2;

		CgsUnicode::CgsUtf8* mpTOS;
	};
}