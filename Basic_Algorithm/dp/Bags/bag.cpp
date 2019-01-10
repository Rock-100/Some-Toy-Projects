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

int dp[N];
pair<int, int> item[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> item[i].weight >> item[i].value;

    memset(dp, 0, sizeof(dp));  ///01
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= item[i].weight; j--)
            dp[j] = max(dp[j], dp[j - item[i].weight] + item[i].value);
    }
    cout << dp[m] << endl;


    memset(dp, 0, sizeof(dp));  ///full
    for (int i = 1; i <= n; i++)
    {
        for (int j = item[i].weight; j <= m; j++)
            dp[j] = max(dp[j], dp[j - item[i].weight] + item[i].value);
    }
    cout << dp[m] << endl;
    return 0;
}

/*
3 7
3 4
4 5
2 3
*/
