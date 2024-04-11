class CgsSystem::HardwareInit
{
    void InitializeHardware(int liArgCount_, char **lpacArgs_, const char *lacWorkingDir_, const char *lacFOPENDir_);

	char* GetWorkingDirectory();

	char* GetFOPENDirectory();
}