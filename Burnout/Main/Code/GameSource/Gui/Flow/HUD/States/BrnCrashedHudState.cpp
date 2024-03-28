namespace BrnGui
{
	bool CrashedHudState::UpdateWFInit()
	{
		if (!(this->mpCache != 0))
		{
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"mpCache");
		}
		// TODO (Decomp): Fix GuiFlow reference
		return GuiCache::AreAllAptComponentsInitialised(this->mpCache, (BrnGui::GuiFlow*)1);
	}
}