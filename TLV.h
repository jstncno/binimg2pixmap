#include <string>
#include <vector>
#include <queue>

#ifndef TLV_H
#define TLV_H

class TLV
{
	public:
		virtual ~TLV();
		int getLength();
		void setLength( char lhs, char rhs );
	protected:
		char type;
		int length;
		int bytes2int( char high, char low ); // concatenates two bytes
};

#endif
