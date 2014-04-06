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

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}

	char t, lhs, rhs, key;

	while( !values.empty() )
	{
		t = values.front();
		values.pop();
		lhs = values.front();
		values.pop();
		rhs = values.front();
		values.pop();
		key = values.front();
		colorMappings[key] = new ColorMappingTLV(t,lhs,rhs,values);
	}
}

ColorTableTLV::~ColorTableTLV()
{
	for (std::map<char,ColorMappingTLV*>::iterator it=colorMappings.begin(); it!=colorMappings.end(); ++it)
		delete colorMappings[it->first];
}