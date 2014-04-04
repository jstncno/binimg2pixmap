#include "TLV.h"

int TLV::bytes2int( char lhs, char rhs )
{
	int length = lhs;
	length = (length << 8) | rhs;
	return length;
}