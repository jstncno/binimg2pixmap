#include "TLV.h"

#ifndef PixelGroupTLV_H
#define PixelGroupTLV_H

class PixelGroupTLV : public TLV
{
	public:
		PixelGroupTLV();
		PixelGroupTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~PixelGroupTLV();

	private:
		std::queue<char> values;
		char num, key;
};

#endif