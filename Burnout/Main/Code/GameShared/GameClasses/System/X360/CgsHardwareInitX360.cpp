// Is this correct? Don't necessarily understand how
// CgsSystem is compiled between different platforms
#include "../CgsHardwareInit.h"

namespace CgsSystem
{
	void CgsSystem::InitializeHardware(int liArgCount_, char **lpacArgs_, const char *lacWorkingDir_, const char *lacFOPENDir_)
	{
		if (lacWorkingDir_) 
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"Can not override working dir on xbox\n");
		}
		if (lacFOPENDir_) 
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"Can not override fopen dir on xbox\n");
		}
		
		// TODO (Decomp): Construct threads, parse autotest arguments, mount utility drive  
	}
}
