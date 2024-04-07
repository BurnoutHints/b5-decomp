#include "BrnPostTitleScreenLoad.h"
namespace BrnGui
{
	void PostTitleScreenLoad::OnLeave()
	{
		CgsGui::StateInterface::UnRegisterForEvents(
			this->mpStateInterface,
			&BrnGui::PostTitleScreenLoad::maiEventToObserve,
			3);
	}
}