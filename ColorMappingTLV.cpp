#include "TLV.h"
#include "ColorMappingTLV.h"

ColorMappingTLV::ColorMappingTLV()
{
	type = 0x04;
	length = 0;
}

ColorMappingTLV::ColorMappingTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}
	while( !values.empty() )
	{
		key = values.front();
		values.pop();
		R = values.front();
		values.pop();
		G = values.front();
		values.pop();
		B = values.front();
		values.pop();
	}
}

ColorMappingTLV::~ColorMappingTLV()
{}

char ColorMappingTLV::getType()
{
	return type;
}