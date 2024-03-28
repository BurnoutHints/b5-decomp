namespace CgsNetwork
{
	class ServerInterfaceComponent
	{
	public:
		virtual ~ServerInterfaceComponent() {}

		virtual void OnEvent(EServerInterfaceEvent leEvent, void* lpData ) = 0;
	};
}
