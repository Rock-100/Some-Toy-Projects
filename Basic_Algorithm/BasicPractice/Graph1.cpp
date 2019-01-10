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

typedef long long LL;

#define N 50
int n, m;
int G[N][N];
bool vis[N];
queue<int> que;

void create()
{
    memset(G, 0, sizeof(G));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = G[b][a] = w;
    }
}

void bfs(int v)
{
    que.push(v);
    vis[v] = 1;
    cout << v << " ";
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (int i = 0; i < n; i++)
        {
            if (!G[p][i] || vis[i])
                continue;
            que.push(i);
            vis[i] = 1;
            cout << i << " ";
        }
    }
    cout << endl;
}

void run_bfs()
{
    cout << "bfs" << endl;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
            bfs(i);
}

void dfs(int v)
{
    vis[v] = 1;
    cout << v << " ";
    for (int i = 0; i < n; i++)
    {
        if (!G[v][i] || vis[i])
            continue;
        dfs(i);
    }
}


void run_dfs()
{
    cout << "dfs" << endl;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            dfs(i);
            cout << endl;
        }
}

int main()
{
    create();

    run_bfs();

    run_dfs();

    return 0;
}

/*

8 7
1 4 1
1 2 2
1 3 1
2 3 3
6 7 2
5 7 4
7 0 1

*/
