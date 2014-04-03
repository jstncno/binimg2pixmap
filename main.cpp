#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main( int argc, char* argv[] )
{
	assert(argc>1);

	ifstream inputFile(argv[1]);

	cout << "Save as: ";
	string outputName;
	cin >> outputName;
	outputName += ".pixmap";
	//ofstream outputFile(outputName.c_str());
	return 0;
}
