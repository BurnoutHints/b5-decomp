#include "Core/CgsAssert.h"

namespace CgsDev
{
	namespace Assert
	{
		void Construct()
		{
			return;
		}

		void FireAssert(
			const char* lpcMessage,
			const char* lpcFile,
			int32_t liLine)
		{
			return;
		}

		void BeginAssert()
		{
			return;
		}

		void EndAssert()
		{
			return;
		}

		void PrintStringed(
			const char* lpcFile,
			const int liLine,
			const char* lacMessage )
		{
			CgsDev::Assert::BeginAssert();
			CgsDev::Assert::FireAssert(lacMessage, lpcFile, liLine);
			CgsDev::Assert::EndAssert();
		}

		void PrintStringless(
			const char* lpcFile,
			const int liLine ) 
		{
			CgsDev::Assert::BeginAssert();
			// Not sure if this is correct behavior
			CgsDev::Assert::FireAssert("", lpcFile, liLine);
			CgsDev::Assert::EndAssert();
		}
	}
}