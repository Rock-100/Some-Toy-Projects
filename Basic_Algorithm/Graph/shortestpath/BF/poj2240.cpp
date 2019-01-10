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
#define N 40
#define M 1000

typedef long long LL;

map<string, int> ID;

struct edge
{
    int from, to;
    double weight;
    edge (int _f = 0, int _t = 0, double _w = 0)
    {
        from = _f, to = _t, weight = _w;
    }
};
int n, m;
edge e[M];

double d[N];
bool find_negative_loop()
{
    fill(d, d + n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[e[j].to] + eps < d[e[j].from] * e[j].weight)
            {
                if (i == n - 1)
                    return true;
                d[e[j].to] = d[e[j].from] * e[j].weight;
            }
        }
    }
    return false;
}

int main()
{
    int cas = 0;
    while (cin >> n && n)
    {
        ID.clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ID[s] = i;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string from, to;
            double w;
            cin >> from >> w >> to;
            e[i] = edge(ID[from], ID[to], w);
        }

        if (find_negative_loop())
            cout << "Case " << ++cas << ": Yes" << endl;
        else
            cout << "Case " << ++cas << ": No" << endl;

    }
    return 0;
}


