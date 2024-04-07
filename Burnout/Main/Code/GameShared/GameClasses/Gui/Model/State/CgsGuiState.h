#include "CgsGuiStateInterface.h"

namespace CgsGui 
{
	class State : public CgsFsm::ScriptedState
	{
	protected:
		InputBuffer::GuiEventQueue* mpInGuiEventQueue;
		
		StateInterface* mpStateInterface;

		bool mbStateChangePending;
	
		char macEvent[16];
	
		bool mbIsSaveLoadState;
	
		bool mbIsVideoState;
	public:
		State();

		virtual void Construct(CgsID lId, CgsFsm::ScriptedFsm* lpFsm);

		virtual void PreWorldUpdate();

		void SetStateInterface(StateInterface *lpStateInterface);

		void SetInEventQueue(InputBuffer::GuiEventQueue *);

		void SendStateEvent(const char* lpacEvent);

		const bool IsVideoState() const;

		const bool IsSaveLoadState() const;

		virtual void GetResourcesToLoad(sResourceTuple **lpaResourceTuples, uint32_t *lpuNumberOfResources);

		virtual void PreUpdate();

		virtual void PostUpdate();
	};
}