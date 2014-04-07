#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <map>

#ifndef TLV_H
#define TLV_H

class TLV
{
	public:
		virtual ~TLV();
		char getType();
		int getLength();
		void setLength( char lhs, char rhs );
		virtual int getNumPixels();
		virtual void queuePixelKeys(std::queue<char> &pixelQueue);
	protected:
		char type;
		int length;
		int bytes2int( char high, char low ); // concatenates two bytes
		std::queue<char> values;
};

#endif
