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
#define N 1010

typedef long long LL;

class BigInteger
{
    friend istream& operator >> (istream&, BigInteger&);
    friend ostream& operator << (ostream&, const BigInteger&);
    friend BigInteger operator + (const BigInteger &, const BigInteger &);
public:
    BigInteger ()
    {
        digit = 1;
        memset(num, 0, sizeof(num));
    }
    BigInteger (int n)
    {
        stringstream ss;
        string s;
        ss << n;
        ss >> s;
        digit = s.size();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < digit; i++)
            num[i] = s[digit - i - 1] - '0';
    }
private:
    int num[50];
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

int n, k;
BigInteger dp[N][110];

int main()
{
    while (cin >> n >> k)
    {
        for (int i = 0; i <= k; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
            {
                if (i < j)
                    dp[i][j] = dp[i][i];
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }

        cout << dp[n][k] << endl;
    }
    return 0;
}
