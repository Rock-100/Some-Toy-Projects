#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

#define eps 1e-10

typedef long long LL;

class BigInteger
{
    friend istream& operator >> (istream&, BigInteger&);
    friend ostream& operator << (ostream&, const BigInteger&);
    friend BigInteger operator + (const BigInteger &, const BigInteger &);
    friend BigInteger operator * (const BigInteger &, const BigInteger &);
public:
    BigInteger ()
    {
        digit = 0;
        memset(num, 0, sizeof(num));
    }
private:
    int num[120];
    int digit;
};

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
    string s(t.digit, '0');
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


int main()
{
    BigInteger a, b;
    while (cin >> a >> b)
    {
        cout << a * b << endl;
    }

    return 0;
}
