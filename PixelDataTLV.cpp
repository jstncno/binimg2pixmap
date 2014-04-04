#include "TLV.h"
#include "PixelDataTLV.h"

PixelDataTLV::PixelDataTLV()
{
	type = 0x03;
	length = 0;
}

PixelDataTLV::PixelDataTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

PixelDataTLV::~PixelDataTLV()
{}