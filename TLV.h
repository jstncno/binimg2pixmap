#ifndef TLV_H
#define TLV_H

class TLV
{
	public:

	protected:
		char type;
		int length;
		int bytes2int( char lhs, char rhs );
};

#endif
