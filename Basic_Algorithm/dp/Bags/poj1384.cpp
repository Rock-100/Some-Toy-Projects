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
#define N 510
#define W 10010
#define value first
#define weight second


typedef long long LL;

int n, w;
int dp[W];
pair<int, int> item[N];

const int inf = 1e9;


int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        int e, f;
        cin >> e >> f;
        w = f - e;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> item[i].value >> item[i].weight;

        dp[0] = 0;
        for (int i = 1; i <= w; i++)
            dp[i] = inf;

        for (int i = 1; i <= n; i++)
        {
            for (int j = item[i].weight; j <= w; j++)
            {
                dp[j] = min(dp[j], dp[j - item[i].weight] + item[i].value);
            }
        }

        if (dp[w] == inf)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[w] << "." << endl;

    }
    return 0;
}

