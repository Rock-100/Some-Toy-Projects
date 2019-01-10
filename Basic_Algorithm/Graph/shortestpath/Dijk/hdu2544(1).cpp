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

int n, m;
int G[N][N];
int d[N];
bool used[N];

int Dijkstra()
{
    for (int i = 2; i <= n; i++)
        d[i] = inf;
    d[1] = 0;
    memset(used, 0, sizeof(used));

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
        if (d[from] == inf)
            break;
        used[from] = 1;
        for (int to = 1; to <= n; to++)
        {
            if (G[from][to] && !used[to])
                d[to] = min(d[to], d[from] + G[from][to]);
        }
    }
    return d[n];
}

int main()
{
    while (cin >> n >> m && n)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; i++)
        {
            int from, to, w;
            cin >> from >> to >> w;
            G[from][to] = w;
            G[to][from] = w;
        }
        cout << Dijkstra() << endl;
    }
    return 0;
}


