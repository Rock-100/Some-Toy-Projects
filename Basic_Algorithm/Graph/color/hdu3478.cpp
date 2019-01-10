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

vector<int> G[N];
int color[N], fa[N];
int n;

void init()
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

bool isCon()
{
    int f = getfa(0);
    for (int i = 1; i < n; i++)
    {
        if (f != getfa(i))
            return false;
    }
    return true;
}

bool dfs(int v, int c)
{
    color[v] = c;

    for (int i = 0; i < G[v].size(); i++)
    {
        int p = G[v][i];
        if (color[p] == c)
            return false;
        else if (!color[p] && !dfs(p, -c))
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int m, s;
        cin >> n >> m >> s;
        for (int i = 0; i < n; i++)
            G[i].clear();
        init();
        while (m--)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            G[s].push_back(t);
            G[t].push_back(s);
            mergefa(s, t);
        }

        if (isCon())
        {
            memset(color, 0, sizeof(color));
            if (dfs(0, 1))
                printf("Case %d: NO\n", cas);
            else
                printf("Case %d: YES\n", cas);
        }
        else
        {
            printf("Case %d: NO\n", cas);
        }
    }
    return 0;
}
