#include "BigInteger.h"



istream& operator >> (istream& in, BigInteger& t)
{
	string s;
	in >> s;
	t.digit = s.size();
	for (int i = 0; i < t.digit; i++)
		t.num[t.digit - 1 - i] = s[i] - '0';
	return in;
}

ostream& operator << (ostream& out, const BigInteger& t)
{
	string s(t.digit, NULL);
	for (int i = 0; i < t.digit; i++)
		s[t.digit - 1 - i] = t.num[i] + '0';
	out << s;
	return out;
}

BigInteger operator + (const BigInteger & a, const BigInteger & b)
{
	BigInteger c;
	c.digit = max(a.digit, b.digit);
	for (int i = 0; i < c.digit; i++)
	{
		c.num[i] += a.num[i] + b.num[i];
		if (c.num[i] > 9)
		{
			c.num[i] -= 10;
			c.num[i + 1] += 1;
		}
	}
	if (c.num[c.digit]) c.digit++;
	return c;
}

BigInteger operator * (const BigInteger & a, const BigInteger & b)
{
	BigInteger c;
	c.digit = a.digit + b.digit;

	for (int i = 0; i < a.digit; i++)
		for (int j = 0; j < b.digit; j++)
			c.num[i + j] += a.num[i] * b.num[j];

	for (int i = 0; i < c.digit - 1; i++)
	{
		if (c.num[i] > 9)
		{
			c.num[i + 1] += c.num[i] / 10;
			c.num[i] = c.num[i] % 10;
		}
	}
	while (c.digit && !c.num[c.digit - 1])
		c.digit--;
	if (!c.digit) c.digit = 1;
	return c;
}