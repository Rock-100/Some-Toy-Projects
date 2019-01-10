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
#define N 100010

typedef long long LL;

int n;
struct SNOW
{
    int f[6];
    int sum;
};
SNOW snow[N];

bool operator < (SNOW a, SNOW b)
{
    return a.sum < b.sum;
}

bool same(int s, int t)
{
    for (int i = 0; i < 6; i++)
    {
        int a, b;
        bool flag = 1;
        for (int k = 0; k < 6; k++)
        {
            a = k, b = (k + i) % 6;
            if (snow[s].f[a] != snow[t].f[b])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
        flag = 1;
        for (int k = 0; k < 6; k++)
        {
            a = k, b = (i - k + 6) % 6;
            if (snow[s].f[a] != snow[t].f[b])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        snow[i].sum = 0;
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &snow[i].f[j]);
            snow[i].sum += snow[i].f[j];
        }
    }

    sort(snow, snow + n);

    for (int i = 0; i < n; i++)
    {
        int s = lower_bound(snow, snow + i, snow[i]) - snow;
        int e = upper_bound(snow, snow + i, snow[i]) - snow;

        for (int j = s; j < e; j++)
        {
            if (same(j, i))
            {
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }
    }
    printf("No two snowflakes are alike.\n");

    return 0;
}
