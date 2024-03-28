namespace CgsNetwork
{
	class ServerInterfaceConnection : public ServerInterfaceComponent
	{
	public:
	    enum EAction
    	{
        	E_ACTION_CONNECTTOSERVER,
        	E_ACTION_ISSUESELECT,
        	E_ACTION_LOGINTOSERVER,
        	E_ACTION_AGREETOS,
        	E_ACTION_AGREESHAREINFO,
        	E_ACTION_COUNT
    	};
	    
		enum ELoginStatus
    	{
        	E_LOGIN_STATUS_INVALID = -1,
        	E_LOGIN_STATUS_OFFLINE = 0,
        	E_LOGIN_STATUS_CONNECT,
        	E_LOGIN_STATUS_LOGIN,
        	E_LOGIN_STATUS_AGREE_TOS,
        	E_LOGIN_STATUS_AGREE_SHARE_INFO,
        	E_LOGIN_STATUS_INAVLID_REGISTRY_KEY,
        	E_LOGIN_STATUS_SELECT_PERSONA,
        	E_LOGIN_STATUS_LOGIN_DONE,
        	E_LOGIN_STATUS_BUSY,
        	E_LOGIN_STATUS_NUM
    	};

		void Construct();

		void Destruct();

		bool Prepare(ServerInterfaceDirtySock* lpServerInterface);

		bool Release();

		void Update();

		void Suspend();

		void Resume();

		ELoginStatus GetLoginStatus();

		bool IsLoggedIn() const;

		bool IsCableConnected() const;

		void DisconnectFromServer();

		bool IsFirstLogin() const;
	};
}