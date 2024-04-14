namespace CgsDev::Log
{
    class LogFile : public CgsDev::StrStreamBase 
    {
    protected:
        #if defined(PLATFORM_X360) || defined(PLATFORM_PC)
        // HANDLE on PC/X360
        HANDLE miFile;
        #else
        // int32_t on PS3
        int miFile;
        #endif

    public:
        // TODO (Decomp): Figure out these constructors' variable names

    	//void LogFile(const LogFile &);

        // Guessed names based on types
    	//void LogFile(const char *lpcFileName_, bool lbAppend_); 

    	void LogFile();

    	void ~LogFile();

    	bool Open(const char *lpcFileName, bool lbAppend);

    	void Close();

    	bool IsOpen() const;

    protected:
    	virtual void Append(const char *lpcString);
    };
}