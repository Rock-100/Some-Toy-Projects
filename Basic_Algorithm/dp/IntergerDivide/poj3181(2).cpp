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

int n, k;
LL dp[N][110][2];
LL MOD = 1e17;

int main()
{
    while (cin >> n >> k)
    {
        for (int i = 0; i <= k; i++)
            dp[0][i][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
            {
                if (i < j)
                {
                    dp[i][j][0] = dp[i][i][0];
                    dp[i][j][1] = dp[i][i][1];
                }
                else
                {
                    dp[i][j][0] = dp[i][j - 1][0] + dp[i - j][j][0];
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i - j][j][1];

                    dp[i][j][1] += dp[i][j][0] / MOD;
                    dp[i][j][0] %= MOD;
                }

            }
        if (dp[n][k][1])
            cout << dp[n][k][1];
        cout << dp[n][k][0] << endl;

    }
    return 0;
}
