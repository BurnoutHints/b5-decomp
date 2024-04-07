#include "CgsGuiState.h"

namespace CgsGui 
{
	void State::SetStateInterface(CgsGui::StateInterface *lpStateInterface)
	{
		if (!(lpStateInterface)) 
		{			
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"Invalid state interface sent to State::SetStateInterface");
		}
		this->mpStateInterface = lpStateInterface;
	}
}