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

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}

	while( !values.empty() )
	{
		key = values.front();
		values.pop();
	}
}

SinglePixelTLV::~SinglePixelTLV()
{}