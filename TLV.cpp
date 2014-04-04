#include "TLV.h"

int TLV::bytes2int( char lhs, char rhs )
{
	int len = lhs;
	len = (len << 8) | rhs;
	return len;
}

TLV::~TLV()
{}

void TLV::setLength( char lhs, char rhs )
{
	length = bytes2int(lhs,rhs);
}