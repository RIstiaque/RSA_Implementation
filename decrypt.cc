#include <iostream>							        
#include <math.h> 
#include <fstream>
#include "numberTheory.h"
#include "ReallyLongInt.h"

using namespace std;

int main(int argc, char** argv)
{
	string s1;
	string s2;
	ifstream fin(argv[1]);
	fin >> s1;
	fin >> s2; // Gets both of the numbers from the private text.
	ReallyLongInt d(s1);
	ReallyLongInt n(s2);
	ifstream ptxt(argv[2]);
	ofstream dtxt(argv[3]);
	ReallyLongInt c;
	string s3;
	while (ptxt >> s3) // Assigns an integer value to c from the textfile. Will end when it reaches the end of the file.
	{
		c = s3;
		ReallyLongInt ans = modPower(c, d, n);
		char c = ans.toLongLong(); // Converting the long long to a character.
		dtxt << c; // Inputting the character to the decrypted text.
	}
}