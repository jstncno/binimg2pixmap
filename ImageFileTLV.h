#include "TLV.h"
#include <vector>

#ifndef ImageFileTLV_H
#define ImageFileTLV_H

class ImageFileTLV : public TLV
{
	public:
		ImageFileTLV();
		ImageFileTLV( char type, char llength, char rlength ); // Take in 3 bytes as parameters
		~ImageFileTLV();
	private:
		std::vector<TLV*> values;
};

#endif
