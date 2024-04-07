#ifdef PLATFORM_PS3
#include "Core/PS3/CgsCorePS3.h"
#endif
#ifdef PLATFORM_X360
#include "Core/X360/CgsCoreX360.h"
#endif
#ifdef PLATFORM_PC
#include "Core/PC/CgsCorePC.h"
#endif

using renderengine;
using rw::math;
using rw::math::vpu;
using rw::math::fpu;
using rw::math::vpl;
using rw::core::stdc;

namespace CgsCore
{
	const int32_t KI_PS2EECACHELINESIZE = 64;

	const int32_t KI_X86CACHELINESIZE = 32;

	const int32_t KI_X64CACHELINESIZE = 64;

	const int32_t KI_PPCCACHELINESIZE = 128;

	const int32_t KI_SPUCACHELINESIZE = 128;

	const int32_t KI_DEBUGMAXVARGSSTRINGLENGTH = 8192;
}