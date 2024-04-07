#include <ctype.h>
#include <stdlib.h>

namespace CgsCore
{
	// Not sure if the param names are correct
	// but still wanted to include the externs
	extern void* MemSet(void* lpDest_, int iCh_, size_t liCount_);

	extern void* MemCpy(void* lpDest_, const void* lpSrc_, size_t liCount_);

	static const int32_t KI_CACHELINESIZE = KI_PPCCACHELINESIZE;
}