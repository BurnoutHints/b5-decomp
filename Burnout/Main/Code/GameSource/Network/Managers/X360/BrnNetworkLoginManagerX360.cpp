#include "Network/Managers/X360/BrnNetworkLoginManagerX360.h"

namespace BrnNetwork 
{
	void LoginManagerX360::PlatformSpecificUpdate()
	{
		EPlatformSpecificUpdate ePlatformSpecificSubState;

		ePlatformSpecificSubState = this->mePlatformSpecificSubState;
		if (ePlatformSpecificSubState)
		{
			if (ePlatformSpecificSubState == E_PLATFORM_SPECIFIC_SUBSTATE_GAMERTAG_SELECTION)
			{
				UpdateGamerTagSelection();
			}
			else
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0,
					"Unknown platform specific update state");
			}
		}
		else
		{
			UpdateSignInToLive();
		}
	}

	void LoginManagerX360::UpdateSignInToLive()
	{

	}

	void LoginManagerX360::UpdateGamerTagSelection()
	{

	}
}