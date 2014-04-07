#include "TLV.h"

#ifndef PixelGroupTLV_H
#define PixelGroupTLV_H

class PixelGroupTLV : public TLV
{
	public:
		PixelGroupTLV();
		PixelGroupTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~PixelGroupTLV();
		char getType();

		int getNumPixels();
		char getNum();
		char getKey();
		void queuePixels(std::queue<char> &pixelQueue);
	private:
		char num, key;
		int numPixels;
};

#endif