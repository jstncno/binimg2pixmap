#include "TLV.h"

int TLV::bytes2int( char high, char low )
{
	int len = high;
	len = (len << 8) | low;
	return len;
}

TLV::~TLV()
{}

int TLV::getLength()
{
	return length;
}

void TLV::setLength( char high, char low )
{
	length = bytes2int(high,low);
}