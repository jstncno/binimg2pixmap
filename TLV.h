#ifndef TLV_H
#define TLV_H

class TLV
{
	public:
		virtual ~TLV();
		void setLength( char lhs, char rhs );
	protected:
		char type;
		int length;
		int bytes2int( char lhs, char rhs );
};

#endif
