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

int dp[2][N];
int n, V;
int value[N];
int volume[N];

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        cin >> n >> V;
        for (int i = 1; i <= n; i++)
            cin >> value[i];
        for (int i = 1; i <= n; i++)
            cin >> volume[i];

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= V; j++)
            {
                bool index = i % 2;
                if (j < volume[i])
                    dp[index][j] = dp[1- index][j];
                else
                    dp[index][j] = max(dp[1-index][j], dp[1-index][j - volume[i]] + value[i]);
            }

        cout << dp[n % 2][V] << endl;
    }
    return 0;
}

