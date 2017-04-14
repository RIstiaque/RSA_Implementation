#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include "ReallyLongInt.h"
#include <climits>


ReallyLongInt::ReallyLongInt() // Creates a RLI with value 0.
{
	isNeg = false;
	unsigned* temp = new unsigned[1];
	temp[0] = 0;
	digits = temp;
	numDigits = 1;
}

ReallyLongInt::ReallyLongInt(long long num) // Creates a RLI from a long long #.
{
	if (num < 0) // Checks negativity.
	{
		isNeg = true;
		num = num * -1;
	}
	else
	{
		isNeg = false;
	}
	if (num == 0)
	{
		numDigits = 1;
	}
	else // Finds the total number of digits.
	{
		numDigits = floor(log10(num)) + 1;
	}
	unsigned* temp = new unsigned[numDigits]; // Creates the array.
	for (unsigned long long i = 0; i < numDigits; i++) // Goes through the array range.
	{
		unsigned long long m = 10;

		for (unsigned long long z = 0; z < (numDigits - i - 1); z++) // Used to find the correct power of 10 for the digit.
		{
			m *= 10;
		}
		unsigned long long d = m / 10; // Used to evaluate the number that goes into the variable using mod.
		unsigned long long var = (num % m) / d;
		temp[i] = var;
	}
	digits = temp;
}

void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) // Removes leading zeros in front of RLI's.
{
	while (x[0] == 0)
	{
		if (x[0] == 0 && xSize != 0)
		{
			for (unsigned i = 0; i < (xSize - 1); i++) // Moves integers over to the left of the array.
			{
				x[i] = x[i + 1];
			}
			xSize -= 1;
		}
		else if (xSize == 0) // Condition for when the number was just 0.
		{
			xSize = 1;
			x[0] = 0;
			break;
		}
		else // Exits while loop. Used break in case by some error 0 is left in the array.
		{
			break;
		}

	}

}

ReallyLongInt::ReallyLongInt(const string& numStr) // Makes a string into a RLI.
{
	numDigits = numStr.size(); // Get string size.
	isNeg = false;
	if (int(numStr[0]) % 100 == 45)
	{
		isNeg = true;
		numDigits = numStr.size() - 1; // Get string size without the sign.
	}
	unsigned* temp = new unsigned[numDigits];
	if (isNeg)
	{
		for (unsigned int i = 0; i < numDigits; i++)
		{
			int c = numStr[i + 1]; // Gets integer value of the character.
			temp[i] = c - 48; // Makes the character into a version of the same integer value.
		}
	}
	else
	{
		for (unsigned int i = 0; i < numDigits; i++)
		{
			int c = numStr[i]; // Gets integer value of the character.
			temp[i] = c - 48; // Makes the character into a version of the same integer value.
		}
	}
	removeLeadingZeros(temp, numDigits); // Removes leading ones.
	if (numDigits == 1 && temp[0] == 0)
	{
		isNeg = false;
	}
	digits = temp;
}

ReallyLongInt::~ReallyLongInt() // Destroys RLI.
{
	delete[] digits;
}

ostream& ReallyLongInt::print(ostream& out) const // Print method for RLI.
{
	if (isNeg)
	{
		out << "-";
	}
	for (unsigned int i = 0; i < numDigits; i++) // Goes through each index in the array.
	{
		out << digits[i];
	}
	return out;
}

ostream& operator<<(ostream& out, const ReallyLongInt& x) // Directs the print method to the right output.
{
	x.print(out);
	return out;
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other) // Gives *this other's properties.
{
	isNeg = other.isNeg;
	numDigits = other.numDigits;
	unsigned* temp = new unsigned[numDigits];
	for (unsigned i = 0; i < numDigits; i++)
	{
		temp[i] = other.digits[i];
	}
	digits = temp;
}

void ReallyLongInt::swap(ReallyLongInt other) // Swaps the properties of this and other.
{
	isNeg = other.isNeg;
	numDigits = other.numDigits;
	const unsigned* temp2 = other.digits;
	other.digits = digits;
	digits = temp2;
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other) // Enables the usage of the '=' operator.
{
	swap(other);
	return *this;
}

ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg) // Creates a RLI using an array, the # of digits, and the negativity value.
{
	removeLeadingZeros(digitsArr, arrSize);
	digits = digitsArr;
	numDigits = arrSize;
	this->isNeg = isNeg;
	if (numDigits == 1 && digits[0] == 0)
	{
		this->isNeg = false;
	}
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const // Evaluates whether two RLI are equal.
{
	if (isNeg != other.isNeg)
	{
		return false;
	}
	if (numDigits != other.numDigits)
	{
		return false;
	}
	for (unsigned long long i = 0; i < numDigits; i++)
	{
		if (digits[i] != other.digits[i])
		{
			return false;
		}
	}
	return true;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const // Evaluates whether one RLI is greater than the other excluding their sign..
{
	if (numDigits < other.numDigits)
	{
		return false;
	}
	if (numDigits > other.numDigits)
	{
		return true;
	}
	for (unsigned long long i = 0; i < numDigits; i++)
	{
		if (digits[i] > other.digits[i])
		{
			return true;
		}
		else if (other.digits[i] > digits[i])
		{
			return false;
		}
	}
	return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const // Evaluates if one RLI is greater than the other with sign included.
{
	if (isNeg != other.isNeg)
	{
		if (isNeg)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (this->equal(other))
		{
			return false;
		}
		else if (isNeg)
		{
			return !absGreater(other);
		}
		return absGreater(other);
	}

}

bool operator==(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '==' operator.
{
	return x.equal(y);
}

bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '!=' operator.
{
	return !(x.equal(y));
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '>' operator.
{
	return x.greater(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '' operator.
{
	return (y.greater(x));
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '>=' operator.
{
	return x.greater(y) || x.equal(y);
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '<=' operator.
{
	return !(x.greater(y)) || x.equal(y);
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const // Adds to absolute RLI's together.
{
	unsigned greater;
	unsigned lesser;
	unsigned resultSize;
	const unsigned* x;
	const unsigned* y;
	if (numDigits > other.numDigits) // To declare which is greater or lesser for the rest of the function.
	{
		x = digits;
		y = other.digits;
		greater = numDigits;
		lesser = other.numDigits;
		resultSize = numDigits + 1;
	}
	else
	{
		x = other.digits;
		y = digits;
		greater = other.numDigits;
		lesser = numDigits;
		resultSize = other.numDigits + 1;
	}
	unsigned* c = new unsigned[resultSize];
	unsigned diff = greater - lesser;
	unsigned temp = 0; // Carry value.
	for (int i = resultSize - 2; i > -1; i--) // Goes through the range.
	{
		if (diff < i + 1) // Adds from the lesser RLI if i + 1 is within range.
		{
			temp += y[i - diff];
		}
		temp += x[i];
		c[i + 1] = temp % 10; // Adds the modded value to the array.
		temp = temp / 10; // Leaves the leftover value for the next value.
	}
	c[0] = temp;

	ReallyLongInt tempArr(c, resultSize, false);
	return tempArr;
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const // Subtracts two RLI from each other excluding sign.
{
	bool isPos;
	unsigned greater;
	unsigned lesser;
	const unsigned* x;
	const unsigned* y;
	if (this->absGreater(other) || this->equal(other))
	{
		greater = numDigits;
		lesser = other.numDigits;
		x = digits;
		y = other.digits;
	}
	else
	{
		greater = other.numDigits;
		lesser = numDigits;
		x = other.digits;
		y = digits;
	}
	int temp = 0; // Borrow value.
	unsigned* c = new unsigned[greater];
	for (unsigned i = 1; i <= greater; i++)
	{
		int z = x[greater - i];
		z -= temp;
		if ((i - 1) < lesser) // Checks if i-1 is within the range of the lesser RLI.
		{
			z -= y[lesser - i];
		}

		temp = 0;
		if (z < 0) // If z becomes negative then the carry value increments by 1 and 10 adds to z to make it positive.
		{
			z += 10;
			temp += 1;
		}
		c[greater - i] = z;
	}
	if (this->greater(other))
	{
		isPos = true;
	}
	else
	{
		isPos = false;
	}
	ReallyLongInt tempArray(c, greater, !isPos);
	return tempArray;
}

void ReallyLongInt::flipSign() // Changes the sign of the RLI.
{
	isNeg = !isNeg;
	if (*this == 0) // If the RLI = 0 then it will not change the sign.
	{
		isNeg = false;
	}
}

ReallyLongInt ReallyLongInt::operator-() const // Makes the RLI into it's opposite sign.
{
	ReallyLongInt temp = *this;
	temp.flipSign();
	return temp;
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const //  Adds two RLI with signs included.
{
	if (isNeg != other.isNeg) // If both have different signs.
	{
		if (this->absGreater(other)) // If *this is greater
		{
			ReallyLongInt temp = this->absSub(other);
			if (temp.isNeg != isNeg)
			{
				temp.flipSign();
			}
			return temp;
		}
		else if (other.absGreater(*this)) // If other is greater
		{
			ReallyLongInt temp = other.absSub(*this);
			if (temp.isNeg != other.isNeg)
			{
				temp.flipSign();
			}
			return temp;
		}
		else // If they're equivalent to eachother.
		{
			ReallyLongInt temp;
			return temp; // Returns RLI(0).
		}
	}
	else
	{
		ReallyLongInt temp = this->absAdd(other);
			if (!isNeg)
			{
				return temp;
			}
			else
			{
				temp.flipSign();
				return temp;
			}
	}
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const // Reroutes the subtraction operators to addition.
{
	ReallyLongInt temp = ReallyLongInt(other);
	temp.flipSign();
	return this->add(temp);
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '+' operator.
{
	return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '-' operator.
{
	return x.sub(y);
}

ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other) // Enables the usage of the '+=' operator.
{
	*this = *this + other;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other) // Enables the usage of the '-=' operator.
{
	*this = *this - other;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator++() // Enables the usage of the '++' operator. 
{
	ReallyLongInt temp(1);
	*this = *this + temp;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator--() // Enables the usage of the '--' operator.
{
	ReallyLongInt temp(1);
	*this = *this - temp;
	return *this;
}

ReallyLongInt ReallyLongInt::operator++(int dummy) // Enables the usage of the '++' operator while returning a copy of the result.
{
	ReallyLongInt temp;
	temp = *this;
	++*this;
	return temp;
}

ReallyLongInt ReallyLongInt::operator--(int dummy) // Enables the usage of the '--' operator while returning a copy of the result.
{
	ReallyLongInt temp;
	temp = *this;
	--*this;
	return temp;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const // Used to multiply two absolute RLI.
{
	unsigned resultSize = numDigits + other.numDigits;
	unsigned* a = new unsigned[resultSize];
	for (int i = 0; i < (numDigits + other.numDigits); i++) // Place 0's in the array.
	{
		a[i] = 0;
	}
	for (unsigned i = 0; i < numDigits; i++) // Goes through each placevalue in the array.
	{
		unsigned c = 0;
		for (unsigned j = 0; j < other.numDigits; j++) // Goes through the other's digits.
		{
			unsigned d = numDigits + other.numDigits - i - j - 1;
			unsigned s = a[d] + (digits[numDigits - i - 1] * other.digits[other.numDigits - j - 1]) + c;
			a[d] = s % 10; // Represents the carry value.
			c = s / 10; // Represents the final value going in the array.
		}
		a[numDigits - i - 1] += c;
	}
	ReallyLongInt tempArr(a, resultSize, false);
	return tempArr;
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const // Calls upon the absMult method based on the RLI's signs.
{
	bool xSign = isNeg;
	bool ySign = other.isNeg;
	ReallyLongInt temp = this->absMult(other);
	if (xSign || ySign)
	{
		if (!xSign || !ySign)
		{
			temp.flipSign();
			return temp;
		}
	}
	return temp;
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '*' operator.
{
	return x.mult(y);
}

ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other) // Enables the usage of the '*=' operator.
{
	*this = *this * other;
	return *this;
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const // *this / other, where *this >= other.
{
	unsigned* tempArray = new unsigned[numDigits];
	ReallyLongInt rem;
	ReallyLongInt other1 = other;
	if (other.isNeg) // Make other positive so subtraction works fine later on.
	{
		other1.flipSign();
	}
	for (unsigned long long i = 0; i < numDigits; i++) // Goes through the array.
	{
		rem *= 10;
		rem += digits[i];
		unsigned long long d = 0; // Keeps tracks of how many times other goes into the remainder.
		while (rem >= other1) // Subtracts other from the remainder
		{
			rem -= other1;
			d += 1;
		}
		tempArray[i] = d;
	}
	remainder = rem;
	quotient = ReallyLongInt(tempArray, numDigits, false);
}

void ReallyLongInt::div(const ReallyLongInt& denominator, ReallyLongInt& quotient, ReallyLongInt& remainder) const // Uses the absDiv appropriately according to sign and initializes it as well.
{
	absDiv(denominator, quotient, remainder);
	if (isNeg != denominator.isNeg && quotient != 0)
	{
		quotient.isNeg = true;
	}
	if (isNeg && remainder != 0)
	{
		remainder.isNeg = true;
	}
	if (quotient == -0)
	{
		quotient.isNeg = false;
	}
}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '/' operator.
{
	ReallyLongInt r;
	ReallyLongInt q;
	x.div(y, q, r);
	return q;
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y) // Enables the usage of the '%' operator.
{
	ReallyLongInt r;
	ReallyLongInt q;
	x.div(y, q, r);
	return r;
}

ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other) // Enables the usage of the '/=' operator.
{
	ReallyLongInt r;
	ReallyLongInt q;
	this->div(other, q, r);
	*this = q;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other) // Enables the usage of the '%=' operator.
{
	ReallyLongInt r;
	ReallyLongInt q;
	this->div(other, q, r);
	*this = r;
	return *this;
}

long long ReallyLongInt::toLongLong() const // Turns a RLI into a Long Long.
{
	ReallyLongInt temp(LLONG_MAX);
	++temp;
	ReallyLongInt Temp2;
	Temp2 = *this;
	ReallyLongInt temp1 = Temp2 % temp;
	unsigned long long ans = 0;
	for (unsigned long long i = 0; i < temp1.numDigits; i++)
	{
		unsigned long long ten = 1;
		for (unsigned long long n = 1; (i != (temp1.numDigits - 1)) && n < temp1.numDigits - i; n++)
		{
			ten *= 10;
		}
		ans += (temp1.digits[i] * ten);
	}
	if (Temp2.isNeg)
	{
		ans = 0 - ans;
	}
	return ans;
}
