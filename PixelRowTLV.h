#include "TLV.h"
#include "PixelGroupTLV.h"
#include "SinglePixelTLV.h"

#ifndef PixelRowTLV_H
#define PixelRowTLV_H

class PixelRowTLV : public TLV
{
	public:
		PixelRowTLV();
		PixelRowTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~PixelRowTLV();

		int getNumPixels();
	private:
		std::vector<SinglePixelTLV*> singlePixels;
		std::vector<PixelGroupTLV*> pixelGroups;
		int numPixels;
};

#endif