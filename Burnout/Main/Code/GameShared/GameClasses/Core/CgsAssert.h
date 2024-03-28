// These aren't implemented yet
#ifdef PLATFORM_PS3
#include "Core/PS3/CgsAssertPS3.h" 
#endif
#ifdef PLATFORM_X360
#include "Core/X360/CgsAssertX360.h"
#endif
#ifdef PLATFORM_PC
#include "Core/PC/CgsAssertPC.h"
#endif

// Guessing here. Not yet sure where these go for sure.
// Will also need to change all current references from
// PrintStringed to ASSERT to get correct file & lines.
#ifdef D_CGS_USEASSERTS
#define ASSERT(expr) PrintStringed(__FILE__,__LINE__,(expr))
#define ASSERT_NOSTRING() PrintStringless(__FILE__,__LINE__)
#else
#define ASSERT(expr)
#define ASSERT_NOSTRING()
#endif

namespace CgsDev
{
	namespace Assert
	{
		void Construct();

		void FireAssert(const char* lpcMessage, const char* lpcFile, int32_t liLine);

		void BeginAssert();

		void EndAssert();

		extern char* gpcMessageBuffer;
		extern int32_t giMessageBufferSize;

		extern void PrintStringed(const char* lpcFile, const int liLine, const char* lacMessage);

		extern void PrintStringless(const char* lpcFile, const int liLine);
	}

	namespace Log
	{
		// extern StrStreamBase* gpAssertPrint;
		// extern StrStreamBase* const gpDefaultAssertPrint;
	}
}
