#include "TLV.h"

#ifndef ColorMappingTLV_H
#define ColorMappingTLV_H

class ColorMappingTLV : public TLV
{
	public:
		ColorMappingTLV();
		ColorMappingTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~ColorMappingTLV();
		char getType();

		void getPixel(std::map<char,char> &pixel);
	private:
		char key,R,G,B;
};

#endif
