#ifndef NUMBERTHEORY_H 
#define NUMBERTHEORY_H
#include "ReallyLongInt.h"

template <class X>

bool isPrime(const X& num)
{
  if (num <= 1)
    {
      return 0;
    }
  else
    {
      for (X i = num / 2; i >= 2; i--)
	{
	  if (num % i == 0)
	    {
	      return  false;
	    }
	}
    }
  return true;
}


template <class X>

X modPower(const X& base, const X& exponent, const X& modulus)
{
  if (exponent == 0)
    {
      return 1;
    }
  X a = (modPower(base, exponent / 2, modulus)) % modulus;
  if (exponent % 2 == 0)
    {
      return ((a) * (a)) % modulus;
    }
  else
    {
      return (((a) * (a) % modulus)) * (base % modulus) % modulus;
    }
}


template <class X>
X extendedEuclid(const X& a, const X& b, X* x, X* y)
{
  if (b == 0)
    {
      *x = 1;
      *y = 0;
      return a;
    }
  else
    {
      X d = extendedEuclid(b, a % b, x, y);
      X t = *y;
      *y = *x - *y * (a / b);
      *x = t;
      return d;
    }
}


#endif

