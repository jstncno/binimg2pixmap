#include "TLV.h"
#include "PixelGroupTLV.h"

PixelGroupTLV::PixelGroupTLV()
{
	type = 0x07;
	length = 0;
}

PixelGroupTLV::PixelGroupTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = 0x07;
	length = bytes2int(llength,rlength);

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}

	while( !values.empty() )
	{
		num = values.front();
		numPixels = num;
		values.pop();
		key = values.front();
		values.pop();
	}
}

PixelGroupTLV::~PixelGroupTLV()
{}

char PixelGroupTLV::getType()
{
	return type;
}

int PixelGroupTLV::getNumPixels()
{
	return numPixels;
}

char PixelGroupTLV::getNum()
{
	return num;
}

char PixelGroupTLV::getKey()
{
	return key;
}

void PixelGroupTLV::queuePixels(std::queue<char> &pixelQueue)
{
	for(int i = 0; i < static_cast<int>(num); i++)
	{
		pixelQueue.push(key);
	}
}