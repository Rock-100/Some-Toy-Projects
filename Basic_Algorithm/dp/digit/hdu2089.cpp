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
#define N 10

typedef long long LL;

int dp[N][N];

void init()
{
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    dp[1][4] = 0;

    for (int i = 2; i <= 7; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j != 4)
            {
                for (int k = 0; k < 10; k++)
                {
                    if (!(j == 6 && k == 2))
                        dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }
}

int ans(int n)
{
    int num[N], digit = 0;
    while (n)
    {
        num[digit++] = n % 10;
        n /= 10;
    }

    int ret = 0;
    for (int i = digit - 1; i >= 0; i--)
    {
        for (int j = 0; j < num[i]; j++)
        {
            if (i != digit - 1 && j == 2 && num[i + 1] == 6)
                continue;
            ret += dp[i + 1][j];
        }

        if (num[i] == 4) break;
        if (i != digit - 1 && num[i] == 2 && num[i + 1] == 6)
            break;
    }
    return ret;
}

int main()
{
    int n, m;
    init();
    while (cin >> n >> m && n)
    {
        cout << ans(m + 1) - ans(n) << endl;
    }
    return 0;
}
