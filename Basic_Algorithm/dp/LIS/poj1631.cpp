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
#define N 40010
#define inf 40010

typedef long long LL;

int num[N];
int dp[N];

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);

        fill(dp, dp + n, inf);
        for (int i = 0; i < n; i++)
        {
            *lower_bound(dp, dp + n, num[i]) = num[i];
        }
        printf("%d\n", lower_bound(dp, dp + n, inf) - dp);
    }
    return 0;
}

