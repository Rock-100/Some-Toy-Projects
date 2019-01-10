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
#define N 600
#define M 6000

typedef long long LL;

struct edge
{
    int from, to, weight;
    edge (int _f = 0, int _t = 0, int _w = 0)
    {
        from = _f, to = _t, weight = _w;
    }
};
int n, m, w, edge_num;
edge e[M];
int d[N];

bool find_negative_loop()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edge_num; j++)
        {
            if (d[e[j].to] > d[e[j].from] + e[j].weight)
            {
                if (i == n - 1)
                    return true;
                d[e[j].to] = d[e[j].from] + e[j].weight;
            }
        }
    }
    return false;
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        cin >> n >> m >> w;
        edge_num = 0;
        for (int i = 0; i < m; i++)
        {
            int from, to, we;
            cin >> from >> to >> we;
            e[edge_num++] = edge(from, to, we);
            e[edge_num++] = edge(to, from, we);
        }
        for (int i = 0; i < w; i++)
        {
            int from, to, we;
            cin >> from >> to >> we;
            e[edge_num++] = edge(from, to, -we);
        }
        if (find_negative_loop())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}


