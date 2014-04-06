#include "TLV.h"
#include "ImageFileTLV.h"
#include "FilenameTLV.h"
#include "ColorTableTLV.h"

ImageFileTLV::ImageFileTLV()
{
	type = 0x01;
	length = 0;
}

ImageFileTLV::ImageFileTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
	char t, lhs, rhs;

	for( int i = 0; i < 3; i++ )
	{
		t = byteStream.front();
		byteStream.pop();
		lhs = byteStream.front();
		byteStream.pop();
		rhs = byteStream.front();
		byteStream.pop();
		switch( t )
		{
			case 0x02:
				filename = new FilenameTLV(t,lhs,rhs,byteStream);
				break;
			case 0x03:
				colorTable = new ColorTableTLV(t,lhs,rhs,byteStream);
				break;
			case 0x05:
				pixelData = new PixelDataTLV(t,lhs,rhs,byteStream);
				break;
			default:
				break;
		}
	}

	numPixelRows = pixelData->getNumPixelRows();
}

ImageFileTLV::~ImageFileTLV()
{
	delete filename;
	delete colorTable;
	delete pixelData;
}

std::string ImageFileTLV::getFilename()
{
	return filename->getFilename();
}

int ImageFileTLV::getNumPixelRows()
{
	return numPixelRows;
}