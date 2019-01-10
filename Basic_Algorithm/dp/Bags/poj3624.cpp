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
#define N 3450
#define M 12900
#define weight first
#define value second

typedef long long LL;

int n, m;
int dp[M];
pair<int, int> item[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> item[i].weight >> item[i].value;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (j >= item[i].weight)
                dp[j] = max(dp[j], dp[j - item[i].weight] + item[i].value);
            else
                dp[j] = dp[j];
        }
    }
    cout << dp[m] << endl;
    return 0;
}

