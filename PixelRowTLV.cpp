#include "TLV.h"
#include "PixelRowTLV.h"

PixelRowTLV::PixelRowTLV()
{
	type = 0x06;
	length = 0;
}

PixelRowTLV::PixelRowTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

PixelRowTLV::~PixelRowTLV()
{}