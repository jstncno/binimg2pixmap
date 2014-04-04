#include "TLV.h"
#include "ColorMappingTLV.h"

ColorMappingTLV::ColorMappingTLV()
{
	type = 0x03;
	length = 0;
}

ColorMappingTLV::ColorMappingTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
	key = byteStream.front();
	byteStream.pop();
	G = byteStream.front();
	byteStream.pop();
	B = byteStream.front();
	byteStream.pop();
}

ColorMappingTLV::~ColorMappingTLV()
{}