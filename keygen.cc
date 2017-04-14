#include <iostream>
#include <math.h>
#include "numberTheory.h"
#include "ReallyLongInt.h"
#include <fstream>
#include <cstdlib>


using namespace std;

int main(int argc, char** argv)
{
  string s1 = argv[1];
  string s2 = argv[2];
  ReallyLongInt p(s1); // Turn the primes into long longs.
  ReallyLongInt q(s2);
  if (0 < p < 100000 && q < 100000)
    {
      if (!(isPrime(p) || isPrime(q))) // Check if really primes.
	{
	  cout << "Error: Arguments are not prime. Please enter two prime numbers." << endl;
	  return 0;
	}
    }
  else
    {
      cout << "Sorry, we cannot check whether prime numbers are greater than 100,000. Thank you. Have a great day." << endl;
    }
  ReallyLongInt n = p * q;
  ReallyLongInt t = (p - 1) * (q - 1);
  ReallyLongInt x = 0;
  ReallyLongInt y = 0;
  ReallyLongInt e = 2;
  for (e; e < t; ++e) // Go through e from 2 until t.
    {
      //cout << "in extendedEuclid" << endl;
      ReallyLongInt a = extendedEuclid(e, t, &x, &y);
      if (a == 1) // Exit for loop if gcd = 1.
	{
	  break;
	}
    }
  if (x < 0) // If x is odd, it will add itself to t.
    {
      x += t;
    }
  ofstream pubIn(argv[3]);
  ofstream priIn(argv[4]);
  pubIn << e << " " << n;
  priIn << x << " " << n; 
}
