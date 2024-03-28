#include "Core/CgsCore.h"

namespace CgsUnicode
{
	typedef uint8_t CgsUtf8;
	typedef uint16_t CgsUtf16;
	typedef uint32_t CgsUtf32;

	static const CgsUtf8 KUTF_NULL = '\0';
	static const CgsUtf8 KUTF_SPACE = ' ';
	static const CgsUtf8 KUTF_NEWLINE = '\n';
	static const CgsUtf8 KUTF_CARRIAGERETURN = '\r';
	static const CgsUtf8 KUTF_ZERO = '0';
	static const CgsUtf8 KUTF_PLUS = '+';
	static const CgsUtf8 KUTF_MINUS = '-';
	static const CgsUtf8 KUTF_DECIMALPOINT = '.';
	static const CgsUtf8 KUTF_COMMA = ',';

	static const CgsUtf8 KUTF8_NON_BREAKING_SPACE[2] = { 0xC2, 0xA0 };

	static const CgsUtf16 KUTF16_NON_BREAKING_SPACE = 0xA0;

	static const uint32_t KU_UNICODE_BUFFER_SIZE = 64;

	static const uint8_t KU_TRAILING_BYTE_MASK = 0xC0;
	static const uint8_t KU_TRAILING_BYTE = 0x80;

	static const uint8_t KU_SINGLE_BYTE_CHAR_MASK = 0x80;
	static const uint8_t KU_SINGLE_BYTE_CHAR = 0x00;

	static const uint8_t KU_TWO_BYTE_CHAR_MASK = 0xE0;
	static const uint8_t KU_TWO_BYTE_CHAR = 0xC0;

	static const uint8_t KU_THREE_BYTE_CHAR_MASK = 0xF0;
	static const uint8_t KU_THREE_BYTE_CHAR = 0xE0;

	static const uint8_t KU_FOUR_BYTE_CHAR_MASK = 0xF8;
	static const uint8_t KU_FOUR_BYTE_CHAR = 0xF0;

	static const uint8_t KAU_TRAILING_BYTE_COUNT[256] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
	};
}