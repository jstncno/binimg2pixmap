#include "TLV.h"
#include "SinglePixelTLV.h"

SinglePixelTLV::SinglePixelTLV()
{
	type = 0x08;
	length = 0;
}

SinglePixelTLV::SinglePixelTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

SinglePixelTLV::~SinglePixelTLV()
{}