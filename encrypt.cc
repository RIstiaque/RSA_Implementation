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
  ifstream fin(argv[1]); // Opens the public text for reading.
  fin >> s1; // Assigns the first integer in the file to this variable, and then the second to n.
  fin >> s2;
  ReallyLongInt e(s1);
  ReallyLongInt n(s2);
  ifstream ptxt(argv[2]); // Opens plaintext to read.
  ofstream fout(argv[3]); // Opens encrypted to write into.
  char c;
  while (ptxt.get(c)) // Continuously gets a character until it reaches the end.
    {
      long long a =  modPower(ReallyLongInt(c), e, n).toLongLong();
      fout << a << endl;
    }
}
