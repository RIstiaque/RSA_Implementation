#include <iostream>
#include <fstream>
#include "ReallyLongInt.h"

using namespace std;

int main(int argc, char** argv) // Determines the factorial of the #.
{
  ReallyLongInt lastVal(argv[1]); //Assign string to rLI type.
  ReallyLongInt curr(1); // Used to multiply to total.
  ReallyLongInt endResult(1); // Keeps track of the end result.
  while (!(lastVal == curr))
    {
      ++curr; // Update curr by 1 every pass.
      endResult *= curr;
    }
  cout << endResult;
}
