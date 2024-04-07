#include "Gui/Model/State/CgsGuiState.h"

namespace BrnGui
{
	class CrashedHudState : CgsGui::State
	{
	public:
		enum CrashInternalState : int
		{
			E_CRASHINTERNALSTATE_GETCACHE = 0x0,
			E_CRASHINTERNALSTATE_LOADING = 0x1,
			E_CRASHINTERNALSTATE_WF_INIT = 0x2,
			E_CRASHINTERNALSTATE_SETUPSTATE = 0x3,
			E_CRASHINTERNALSTATE_RUNNING = 0x4,
			E_CRASHINTERNALSTATE_IDLE = 0x5,
			E_CRASHINTERNALSTATE_COUNT = 0x6,
		};

	private:
		bool UpdateWFInit();
	};
}