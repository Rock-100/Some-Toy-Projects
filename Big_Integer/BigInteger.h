#ifndef __BIGINTEGER__
#define __BIGINTEGER__

#include "Common.h"

class BigInteger
{
	friend istream& operator >> (istream&, BigInteger&);
	friend ostream& operator << (ostream&, const BigInteger&);
	friend BigInteger operator + (const BigInteger &, const BigInteger &);
	friend BigInteger operator * (const BigInteger &, const BigInteger &);
public:
	BigInteger()
	{
		digit = 0;
		memset(num, 0, sizeof(num));
	}
	BigInteger(string s)
	{
		digit = s.size();
		memset(num, 0, sizeof(num));
		for (int i = 0; i < digit; i++)
			num[digit - 1 - i] = s[i] - '0';
	}

	BigInteger(int n)
	{
		stringstream ss;
		ss << n;
		string s = ss.str();
		digit = s.size();
		memset(num, 0, sizeof(num));
		for (int i = 0; i < digit; i++)
			num[digit - 1 - i] = s[i] - '0';

	}

private:
	int num[120];
	int digit;
};

istream& operator >> (istream& in, BigInteger&);

ostream& operator << (ostream& out, const BigInteger&);

BigInteger operator + (const BigInteger &, const BigInteger &);

BigInteger operator * (const BigInteger &, const BigInteger &);


#endif 
