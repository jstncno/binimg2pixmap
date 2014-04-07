#include "TLV.h"
#include "PixelRowTLV.h"

#ifndef PixelDataTLV_H
#define PixelDataTLV_H

class PixelDataTLV : public TLV
{
	public:
		PixelDataTLV();
		PixelDataTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~PixelDataTLV();
		char getType();

		int getNumPixelsPerPixelRow();
		int getNumPixelRows();
		void queuePixelsAtRow(int row,std::queue<char> &pixels);
	private:
		std::vector<PixelRowTLV*> pixelRows;
		int numPixelsPerPixelRow;
		int numPixelRows;
};

#endif