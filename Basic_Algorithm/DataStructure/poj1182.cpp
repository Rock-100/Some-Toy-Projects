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
#define N 200000

typedef long long LL;

int fa[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
}

int getfa(int x)
{
    if (x == fa[x])
        return x;
    else
    {
        fa[x] = getfa(fa[x]);
        return fa[x];
    }
}

bool isjoint(int x, int y)
{
    x = getfa(x);
    y = getfa(y);
    return x == y;
}

void mergefa(int x, int y)
{
    x = getfa(x);
    y = getfa(y);
    fa[x] = y;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    init(3 * n);
    int ans = 0;
    while (k--)
    {
        int label, x, y;
        scanf("%d%d%d", &label, &x, &y);
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (label == 2 && x == y)
        {
            ans++;
            continue;
        }
        x--, y--;
        if (label == 1)
        {
            if (isjoint(x, y + n) || isjoint(x + n, y))
            {
                ans++;
            }
            else
            {
                mergefa(x, y);
                mergefa(x + n, y + n);
                mergefa(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            if (isjoint(x, y) || isjoint(x + n, y))
            {
                ans++;
            }
            else
            {
                mergefa(x, y + n);
                mergefa(x + n, y + 2 * n);
                mergefa(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
