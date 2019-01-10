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
#define N 1000
#define weight first
#define value second

typedef long long LL;

int dp[N][N];
pair<int, int> item[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> item[i].weight >> item[i].value;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= item[i].weight)
                dp[i][j] = max(dp[i][j], dp[i][j - item[i].weight] + item[i].value);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

/*
3 7
3 4
4 5
2 3
*/
