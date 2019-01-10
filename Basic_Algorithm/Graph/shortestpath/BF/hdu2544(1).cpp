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

int n, m;
int G[N][N];
int d[N][N];

int BF()
{
    for (int i = 1; i <= n; i++)
        d[0][i] = inf;
    d[0][1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int to = 1; to <= n; to++)
        {
            d[i][to] = d[i - 1][to];
            for (int from = 1; from <= n; from++)
            {
                if (G[from][to] && d[i - 1][from] != inf)
                    d[i][to] = min(d[i][to], d[i - 1][from] + G[from][to]);

            }
        }
    }

    return d[n - 1][n];
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

        cout << BF() << endl;
    }
    return 0;
}


