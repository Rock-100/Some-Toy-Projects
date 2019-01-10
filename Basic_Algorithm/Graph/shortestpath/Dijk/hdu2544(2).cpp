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
#define N 110
#define M 20010
#define inf (1<<30)

typedef long long LL;

struct edge
{
    int to, weight;
    edge (int _t = 0, int _w = 0)
    {
        to = _t, weight = _w;
    }
};

int n, m;
vector<edge> G[N];
int d[N];
bool used[N];

int Dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf, used[i] = 0;
    }
    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int from = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!used[j])
            {
                if (!from) from = j;
                else if (d[j] < d[from])
                    from = j;
            }
        }
        if (d[from] == inf) break;
        used[from] = 1;

        for (int j = 0; j < G[from].size(); j++)
            d[G[from][j].to] = min(d[G[from][j].to], d[from] + G[from][j].weight);
    }

    return d[n];
}

int main()
{
    while (cin >> n >> m && n)
    {
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 0; i < m; i++)
        {
            int from, to, w;
            cin >> from >> to >> w;
            G[from].push_back(edge(to, w));
            G[to].push_back(edge(from, w));
        }
        cout << Dijkstra() << endl;
    }
    return 0;
}


