#include "TLV.h"
#include "PixelDataTLV.h"

PixelDataTLV::PixelDataTLV()
{
	type = 0x05;
	length = 0;
}

PixelDataTLV::PixelDataTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
}

PixelDataTLV::~PixelDataTLV()
{
	for( int i = 0; i < values.size(); i++ )
	{
		delete values[i];
	}
}