#include "Core/CgsDebugManager.h"

namespace CgsDev 
{
	void DebugManager::RenderHUD()
	{
		if (!(this->mp2dRender != 0)) 
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"must call ConstructRenderer"); 
		}

		Debug2DImmediateRender::Begin(this->mp2dRender);
		DebugRender::Dispatch2D(&this->mBufferedRenderer, this->mp2dRender, 1);
	
		//TODO (Decomp): Gibberish! Find the correct way to add to render
		/*
		for (int i = this->mComponentList; i; i = *(i + 8) )
		{
			if ( *(i + 4) )
			{
				(*(*i + 8))(i, this->mp2dRender);
			}
		}
		*/

		DebugUI::DebugUI::Render(this->mpUI);
		Debug2DImmediateRender::End(this->mp2dRender);
	}

	void DebugManager::SetGamePad(DebugManagerPad *lpDebugManagerPad)
	{
		// Move to DebugUI::DebugUI::SetGamePad in CgsDevelopmentUnity.cpp
		this->mpUI->mController.mpDebugManagerPad = lpDebugManagerPad;
	}
}