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

vector<int> G[N];
int vis[N];
int n, m;

void dfs(int v)
{
    vis[v] = 1;
    cout << v << " ";

    for (int i = 0; i < G[v].size(); i++)
    {
        if (!vis[G[v][i]])
            dfs(G[v][i]);
    }
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            int s, t;
            cin >> s >> t;
            G[s].push_back(t);
            G[t].push_back(s);
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
