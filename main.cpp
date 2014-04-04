#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main( int argc, char* argv[] )
{
	assert(argc>1);

	ifstream inputFile;
	inputFile.open(argv[1],ios::binary | ios::in);

	char byte;
	inputFile.read(&byte,sizeof(char));

	return 0;
}
