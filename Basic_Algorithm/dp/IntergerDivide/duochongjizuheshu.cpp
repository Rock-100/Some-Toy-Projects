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

int n, k;
int num[N];
int dp[N][N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (j - num[i] - 1 >= 0)
                dp[i][j] -= dp[i - 1][j - num[i] - 1];
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}

/*
3 3
1
2
3

*/
