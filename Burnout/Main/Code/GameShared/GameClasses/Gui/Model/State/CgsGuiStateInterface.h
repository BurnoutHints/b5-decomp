namespace CgsGui 
{
	class StateInterface 
	{
		EventObserver *mpObserver;
		GuiAccessPointers *mpAccessPointers;
		rw::IResourceAllocator *mpAllocator;
		GuiEventQueueLarge mOutEventQueue;
	};
}