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
#define N 100
#define V 100
#define weight first
#define value second
#define inf (1 << 30)

typedef long long LL;

int n, w;
int dp[N * V];
pair<int, int> item[N];

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> item[i].weight >> item[i].value;

    fill(dp, dp + N * V, inf);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = N * V - 1; j >= item[i].value; j--)
            dp[j] = min(dp[j], dp[j - item[i].value] + item[i].weight);
    }
    int res = 0;
    for (int i = 0; i < N * V; i++)
        if (dp[i] <= w)
            res = i;
    cout << res << endl;

    return 0;
}

/*
3 7
3 4
4 5
2 3
*/

