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

int dp[N][N];

int main()
{
    int n = 100;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i < j)
                dp[i][j] = dp[i][i];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }


    while (cin >> n)
    {
        cout << dp[n][n] << endl;
    }
    return 0;
}
