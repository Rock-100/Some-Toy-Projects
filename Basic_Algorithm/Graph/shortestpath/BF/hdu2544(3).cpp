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
#define M 10010
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

int BF()
{
    for (int i = 2; i <= n; i++)
        d[i] = inf;
    d[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int from = 1; from <= n; from++)
        {
            if (d[from] != inf)
            {
                for (int j = 0; j < G[from].size(); j++)
                    d[G[from][j].to] = min(d[G[from][j].to], d[from] + G[from][j].weight);
            }
        }
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

        cout << BF() << endl;
    }
    return 0;
}


