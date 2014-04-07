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
	length = bytes2int(llength,rlength);

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}

	char t, lhs, rhs;

	while( !values.empty() )
	{
		t = values.front();
		values.pop();
		lhs = values.front();
		values.pop();
		rhs = values.front();
		values.pop();
		switch( t )
		{
			case 0x02:
				filename = new FilenameTLV(t,lhs,rhs,values);
				break;
			case 0x03:
				colorTable = new ColorTableTLV(t,lhs,rhs,values);
				break;
			case 0x05:
				pixelData = new PixelDataTLV(t,lhs,rhs,values);
				break;
			default:
				break;
		}
	}

	numPixelsPerPixelRow = pixelData->getNumPixelsPerPixelRow();
	numPixelRows = pixelData->getNumPixelRows();
}

ImageFileTLV::~ImageFileTLV()
{
	delete filename;
	delete colorTable;
	delete pixelData;
}

char ImageFileTLV::getType()
{
	return type;
}

std::string ImageFileTLV::getFilename()
{
	return filename->getFilename();
}

int ImageFileTLV::getNumPixelsPerPixelRow()
{
	return numPixelsPerPixelRow;
}

int ImageFileTLV::getNumPixelRows()
{
	return numPixelRows;
}

void ImageFileTLV::queuePixelKeysAtRow(int row, std::queue<char> &pixels)
{
	pixelData->queuePixelKeysAtRow(row,pixels);
}

void ImageFileTLV::getPixelAtKey(char key, std::map<char,unsigned char> &pixel)
{
	colorTable->getPixelAtKey(key,pixel);
}