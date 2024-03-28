namespace CgsGui 
{
	class State
	{
		void SetStateInterface(CgsGui::StateInterface *lpStateInterface);

		// Not sure if this is supposed to be virtual, 
		// and if so, is the one above supposed to be as well?
		virtual void GetResourcesToLoad(CgsGui::sResourceTuple **lpaResourceTuples, uint32_t *lpuNumberOfResources);

	private:
		CgsGui::StateInterface *mpStateInterface;
	};
}