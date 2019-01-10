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
DP dp;

int main()
{

    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        bool flag = 0;
        for (int i = 0; i < n; i++)
            if (num[i] >= 0) flag = 1;
        if (!flag)
        {
            printf("0 %d %d\n", num[0], num[n - 1]);
            continue;
        }
        dp = DP(num[0], 0, 0);
        DP ans = dp;
        for (int i = 1; i < n; i++)
        {
            if (dp.va >= 0)
                dp = DP(dp.va + num[i], dp.s, i);
            else
                dp = DP(num[i], i, i);
            if (ans.va < dp.va)
                ans = dp;
        }
        printf("%d %d %d\n", ans.va, num[ans.s], num[ans.t]);
    }

    return 0;
}
