namespace CgsGui 
{
	class GuiAccessPointers
	{
		AptAux *mpAptAux;
		CgsLanguage::LanguageManager *mpLanguageManager;
		BrnFlapt::FileRef *mpFlaptFile;
		BrnGui::GuiCache *mpGuiCache;
		BrnFlapt::FlaptManager *mpFlaptManager;
		BrnResource::GameDataIO::InputBuffer *mpGDMInput;
		GuiEventReceiverQueue *mpGDMReceiverQueue;
	};
}