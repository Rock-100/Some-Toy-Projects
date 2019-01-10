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
    int from, to, weight;
    edge (int _f = 0, int _t = 0, int _w = 0)
    {
        from = _f, to = _t, weight = _w;
    }
};

int n, m;
edge e[M];
int d[N];

int BF()
{
    for (int i = 2; i <= n; i++)
        d[i] = inf;
    d[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2 * m; j++)
        {
            if (d[e[j].from] != inf)
                d[e[j].to] = min(d[e[j].to], d[e[j].from] + e[j].weight);
        }
    }

    return d[n];
}

int main()
{
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < m; i++)
        {
            int from, to, w;
            cin >> from >> to >> w;
            e[i] = edge(from, to, w);
            e[i + m] = edge(to, from, w);
        }

        cout << BF() << endl;
    }
    return 0;
}


