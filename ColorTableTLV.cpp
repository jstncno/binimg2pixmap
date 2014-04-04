#include "TLV.h"
#include "ColorTableTLV.h"
#include "ColorMappingTLV.h"

ColorTableTLV::ColorTableTLV()
{
	type = 0x03;
	length = 0;
}

ColorTableTLV::ColorTableTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
	numColorMaps = length/7; //7 is the number of bytes a ColorMappingTLV has
	char t, lhs, rhs, key;

	for( int i = 0; i < numColorMaps; i++ )
	{
		t = byteStream.front();
		byteStream.pop();
		lhs = byteStream.front();
		byteStream.pop();
		rhs = byteStream.front();
		byteStream.pop();
		key = byteStream.front();
		values[key] = new ColorMappingTLV(t,lhs,rhs,byteStream);
	}
}

ColorTableTLV::~ColorTableTLV()
{
	for (std::map<char,ColorMappingTLV*>::iterator it=values.begin(); it!=values.end(); ++it)
		delete values[it->first];
}