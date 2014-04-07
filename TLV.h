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
		virtual char getType() = 0;
		int getLength();
		void setLength( char lhs, char rhs );
		virtual int getNumPixels();
	protected:
		char type;
		int length;
		int bytes2int( char high, char low ); // concatenates two bytes
		std::queue<char> values;
};

#endif
