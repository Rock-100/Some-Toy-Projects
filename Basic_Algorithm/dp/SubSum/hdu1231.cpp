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
#define N 10010

typedef long long LL;

int n;
int num[N];
struct DP
{
    int va, s, t;
    DP(int _va = 0, int _s = 0, int _t = 0):va(_va), s(_s), t(_t)
    {
    }
};
DP dp[N];

int main()
{

    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        dp[0] = DP(num[0], 0, 0);
        DP ans;
        if (dp[0].va >= 0)
            ans = dp[0];
        else
            ans = DP(-1, 0, n - 1);
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1].va >= 0)
                dp[i] = DP(dp[i - 1].va + num[i], dp[i - 1].s, i);
            else
                dp[i] = DP(num[i], i, i);
            if (ans.va < dp[i].va)
                ans = dp[i];
        }
        if (ans.va == -1) ans.va = 0;
        printf("%d %d %d\n", ans.va, num[ans.s], num[ans.t]);
    }

    return 0;
}
