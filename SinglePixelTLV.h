#include "TLV.h"

#ifndef SinglePixelTLV_H
#define SinglePixelTLV_H

class SinglePixelTLV : public TLV
{
	public:
		SinglePixelTLV();
		SinglePixelTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~SinglePixelTLV();
		char getType();

		int getNumPixels();
	private:
		char key;
		int numPixels;
};

#endif