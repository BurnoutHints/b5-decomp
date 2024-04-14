#include "CgsLogFile.h"

// Currently, we're treating X360 and PC's logic as the same, mainly
// because X360's file IO logic is just standard Windows API calls.
//
// This may need to be changed in the future.

namespace CgsDev::Log
{
	bool LogFile::Open(const char *lpcFileName, bool lbAppend)
	{
		bool mSuccess_; // Is this success? Or failure?

		if (lbAppend)
		{		
			#if defined(PLATFORM_PS3)
			uint64_t lNewPos;
			
			// 65 = CELL_FS_O_WRONLY | CELL_FS_O_CREAT
			if (cellFsOpen(lpcFileName, 65, &this->miFile, NULL, 0))
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0, 
					"cellFsOpen(lpcFileName,CELL_FS_O_WRONLY | CELL_FS_O_CREAT, &miFile, NULL, 0) == CELL_FS_OK");
					
				if (!cellFsLseek(this->miFile, 0, 2, lNewPos))
				{
					return true;
				}
			}
			
			// 2 = CELL_FS_SEEK_END
			else if (!cellFsLseek(this->miFile, 0, 2, lNewPos))
			{
				return true;
			}
			
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"cellFsLseek(miFile, 0, CELL_FS_SEEK_END, &lNewPos) == CELL_FS_OK");
			#endif

			#if defined(PLATFORM_X360) || defined(PLATFORM_PC)
			// 0x40000000 = GENERIC_WRITE (Generic Access Rights)
			// 2 = FILE_SHARE_WRITE
			// 4 = OPEN_ALWAYS
			HANDLE mFileHandle = CreateFileA(lpcFileName, 0x40000000, 2, 0, 4, 0, 0);
			
			this->miFile = (int)mFileHandle;
			
			if (!(mFileHandle != -1))
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0, 
					"mFileHandle != INVALID_HANDLE_VALUE"); 
			}
			
			// 2 = FILE_END
			SetFilePointer((HANDLE)this->miFile, 0, 0, 2);
			#endif

			mSuccess_ = true;
		}
		else
		{
			#if defined(PLATFORM_PS3)
			// 577 = CELL_FS_O_WRONLY | CELL_FS_O_CREAT | CELL_FS_O_TRUNC
			if (!cellFsOpen(lpcFileName, 577, &this->miFile, NULL, 0)) 
			{
				return true;
			}
			
			CgsDev::Assert::PrintStringed(
				"UPDATE ME", 0, 
				"cellFsOpen(lpcFileName,CELL_FS_O_WRONLY | CELL_FS_O_CREAT | CELL_FS_O_TRUNC, &miFile, NULL, 0) == CELL_FS_OK");
			#endif
			
			#if defined(PLATFORM_X360) || defined(PLATFORM_PC)
			// 0x40000000 = GENERIC_WRITE (Generic Access Rights)
			// 2 = FILE_SHARE_WRITE
			// 2 = CREATE_ALWAYS
			HANDLE mFileHandle = CreateFileA(lpcFileName, 0x40000000, 2, 0, 2, 0, 0);
			
			this->miFile = mFileHandle;
			
			// -1 = INVALID_HANDLE_VALUE
			if (!(mFileHandle != -1))
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0, 
					"mFileHandle != INVALID_HANDLE_VALUE"); 
			}

			// This always seems to return true on Xbox 360?
			mSuccess_ = true;
			#endif
		}

		return mSuccess_;
	}

	void LogFile::Close()
	{
		#if defined(PLATFORM_PS3)
		if (this->miFile >= 0)
		{
			if (!(cellFsClose(this->miFile) == 0))
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0, 
					"cellFsClose(miFile) == CELL_FS_OK"); 
			}
		}
		#endif

		#if defined(PLATFORM_X360) || defined(PLATFORM_PC)
		if (this->miFile != -1)
		{
			CloseHandle((HANDLE)this->miFile);
			// -1 = INVALID_HANDLE_VALUE
			this->miFile = -1;
		}
		#endif
	}

	void LogFile::Append(const char *lpcString)
	{
		#if defined(PLATFORM_PS3)
		if (this->miFile >= 0)
		{
			uint64_t *lNewPos;
			// uint64_t strlen cast may not be required
			// 0 = CELL_FS_OK
			if (!(cellFsWrite(this->miFile, lpcString, (uint64_t)strlen(lpcString), lNewPos) == 0))
			{
				CgsDev::Assert::PrintStringed(
					"UPDATE ME", 0, 
					"cellFsWrite(miFile, lpcString, strlen(lpcString), &lNewPos) == CELL_FS_OK"); 
			}
		}
		#endif
		#if defined(PLATFORM_X360) || defined(PLATFORM_PC)
		// -1 = INVALID_HANDLE_VALUE
		if (miFile != -1) 
		{
			DWORD mBytesWritten = 0;
			DWORD mStrLen = strlen(lpcString);

			// (Decomp) Added this check since WriteFile is synchronous!
			if (mStrLen > 0) 
			{
				WriteFile(miFile, lpcString, mStrLen, &mBytesWritten, NULL);
			}
		}
		#endif
	}
}