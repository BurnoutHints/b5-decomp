#include "Network/Managers/BrnNetworkLoginManagerBase.h"

namespace BrnNetwork 
{
	class LoginManagerX360 : BrnNetwork::LoginManagerBase 
	{
		// A lot of this is most likely supposed to be handled
		// in LoginManagerBase then overridden in this class.

		enum EPlatformSpecificUpdate : int 
		{
			E_PLATFORM_SPECIFIC_SUBSTATE_UNK0 = 0x0,
			E_PLATFORM_SPECIFIC_SUBSTATE_GAMERTAG_SELECTION = 0x1,
			E_PLATFORM_SPECIFIC_SUBSTATE_COUNT = 0x2
		};

		EPlatformSpecificUpdate mePlatformSpecificSubState;
		
		void PlatformSpecificUpdate(); 

		void UpdateSignInToLive();
		void UpdateGamerTagSelection();
	};
}