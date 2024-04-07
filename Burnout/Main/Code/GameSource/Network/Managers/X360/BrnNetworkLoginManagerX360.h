#include "Network/Managers/BrnNetworkLoginManagerBase.h"

namespace BrnNetwork 
{
	class LoginManagerX360 : LoginManagerBase 
	{
	public:
		enum EPlatformSpecificSubState : int 
		{
			E_PLATFORM_SPECIFIC_SUBSTATE_UNK0 = 0x0,
			E_PLATFORM_SPECIFIC_SUBSTATE_GAMERTAG_SELECTION = 0x1,
			E_PLATFORM_SPECIFIC_SUBSTATE_COUNT = 0x2
		};

		LoginManagerX360();

		void Construct(BrnNetworkModule* lpNetworkModule);

		bool Prepare();

		bool Release();

		void Destruct();

		virtual void Start(ESignInType leSignInType);

		virtual void Disconnected();

	protected:
		virtual void PlatformSpecificUpdate(const BrnNetworkModuleIO::PostSimulationInputBuffer* lpInput); 
	
		virtual void GetUserNameAndPassword(char* lacUserName, char* lacPassword);

	private:
		EPlatformSpecificSubState mePlatformSpecificSubState;
			
		void UpdateSignInToLive();

		void UpdateGamerTagSelection();
	};
}