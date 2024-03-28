namespace CgsGui 
{
	class StateInterface 
	{
		CgsGui::EventObserver *mpObserver;
		CgsGui::GuiAccessPointers *mpAccessPointers;
		rw::IResourceAllocator *mpAllocator;
		CgsGui::GuiEventQueueLarge mOutEventQueue;
	};
}