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
		void queuePixelKeysAtRow(int row, std::queue<char> &pixels); //queues the keys for the pixel maps
		void getPixelAtKey(char key, std::map<char,unsigned char> &pixel); //retrieves R, B, and G pixel values from pixel map with key
	private:
		FilenameTLV* filename;
		ColorTableTLV* colorTable;
		PixelDataTLV* pixelData;
		int numPixelsPerPixelRow;
		int numPixelRows;
};

#endif
