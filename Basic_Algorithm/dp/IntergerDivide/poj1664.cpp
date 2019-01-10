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
#define N 20

typedef long long LL;

int dp[N][N];

int main()
{
    int t;
    cin >> t;
    dp[0][0] = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j - 1];
                if (i >= 2 * j)
                    dp[i][j] += dp[i - j][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= k; i++)
            res += dp[n][i];
        cout << res << endl;
    }
    return 0;
}
