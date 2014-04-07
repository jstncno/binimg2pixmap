#include "TLV.h"

int TLV::bytes2int( char high, char low )
{
	int len = 0;
	len = len | high;
	len = (len << 8) | (low & 0xFF);
	return abs(len);
}

TLV::~TLV()
{}

char TLV::getType()
{
	return type;
}

int TLV::getLength()
{
	return length;
}

int TLV::getNumPixels()
{
	return -1;
}

void TLV::setLength( char high, char low )
{
	length = bytes2int(high,low);
}