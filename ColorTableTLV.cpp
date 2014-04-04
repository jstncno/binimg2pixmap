#include "TLV.h"
#include "ColorTableTLV.h"

ColorTableTLV::ColorTableTLV()
{
	type = 0x03;
	length = 0;
}

ColorTableTLV::ColorTableTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

ColorTableTLV::~ColorTableTLV()
{}