#include "TLV.h"

#ifndef PixelRowTLV_H
#define PixelRowTLV_H

class PixelRowTLV : public TLV
{
	public:
		PixelRowTLV();
		PixelRowTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~PixelRowTLV();

	private:

};

#endif