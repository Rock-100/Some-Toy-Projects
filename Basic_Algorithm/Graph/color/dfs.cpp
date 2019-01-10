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
#define N 100

typedef long long LL;

int G[N][N];
int vis[N];
int n, m;

void dfs(int v)
{
    vis[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++)
    {
        if (G[v][i] && !vis[i])
            dfs(i);
    }
}

int main()
{
    while (cin >> n >> m)
    {
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            int s, t;
            cin >> s >> t;
            G[s][t] = G[t][s] = 1;
        }
        dfs(0);
    }

    return 0;
}


/*
3 3
0 1
0 2
1 2

4 4
0 1
0 3
2 3
2 1

5 4
0 1
0 3
0 4
2 3

*/
