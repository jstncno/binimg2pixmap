#include "TLV.h"
#include "FilenameTLV.h"
#include "ColorTableTLV.h"
#include "PixelDataTLV.h"
#include "PixelRowTLV.h"

#ifndef ImageFileTLV_H
#define ImageFileTLV_H

class ImageFileTLV : public TLV
{
	public:
		ImageFileTLV();
		ImageFileTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~ImageFileTLV();
		char getType();

		std::string getFilename();
		int getNumPixelsPerPixelRow();
		int getNumPixelRows();
		void queuePixelsAtRow(int row, std::queue<char> &pixels); //queues the keys for the pixel maps
	private:
		FilenameTLV* filename;
		ColorTableTLV* colorTable;
		PixelDataTLV* pixelData;
		int numPixelsPerPixelRow;
		int numPixelRows;
};

#endif
