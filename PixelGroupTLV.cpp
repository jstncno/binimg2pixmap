#include "TLV.h"
#include "PixelGroupTLV.h"

PixelGroupTLV::PixelGroupTLV()
{
	type = 0x07;
	length = 0;
}

PixelGroupTLV::PixelGroupTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

PixelGroupTLV::~PixelGroupTLV()
{}