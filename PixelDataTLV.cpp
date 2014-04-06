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
		pixelRows.push_back(new PixelRowTLV(t,lhs,rhs,values));
	}
}

PixelDataTLV::~PixelDataTLV()
{
	for( int i = 0; i < pixelRows.size(); i++ )
	{
		delete pixelRows[i];
	}
}