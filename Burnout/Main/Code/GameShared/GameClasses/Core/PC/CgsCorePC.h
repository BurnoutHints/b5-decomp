#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

namespace CgsCore
{
	// TODO (Decomp): Change depending on 32/64bit build configs
	// KI_X86CACHELINESIZE <-> KI_X64CACHELINESIZE
	static const int32_t KI_CACHELINESIZE = KI_X86CACHELINESIZE;
}
