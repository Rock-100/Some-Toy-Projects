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

struct edge
{
    int to, cost;
    edge (int _t = 0, int _c = 0)
    {
        to = _t;
        cost = _c;
    }
};
vector<edge> G[N];
int n;
int point, maxdis;
int dis[N];

void init(int v)
{
    maxdis = 0;
    memset(dis, -1, sizeof(dis));
    dis[v] = 0;
}

void dfs(int v)
{
    for (int i = 0; i < G[v].size(); i++)
    {
        edge p = G[v][i];
        if (dis[p.to] == -1)
        {
            dis[p.to] = dis[v] + p.cost;
            if (dis[p.to] > maxdis)
            {
                point = p.to;
                maxdis = dis[p.to];
            }
            dfs(p.to);
        }
    }
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int s, t, w;
        char c[10];
        scanf("%d%d%d%s", &s, &t, &w, c);
        G[s].push_back(edge(t, w));
        G[t].push_back(edge(s, w));
    }

    init(1);
    dfs(1);
    init(point);
    dfs(point);
    printf("%d\n", maxdis);

    return 0;
}
