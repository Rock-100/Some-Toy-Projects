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
vector<vector<pair<int, int> > > G;
bool vis[N];
queue<int> que;
int n, m;

void create()
{
    G.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        G.push_back(vector<pair<int, int> > ());
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(make_pair(b, w));
        G[b].push_back(make_pair(a, w));
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
        for (int i = 0; i < G[p].size(); i++)
        {
            int q = G[p][i].first;
            if (vis[q])
                continue;
            que.push(q);
            vis[q] = 1;
            cout << q << " ";
        }
    }
}

void run_bfs()
{
    cout << "bfs" << endl;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            bfs(i);
            cout << endl;
        }
}

void dfs(int v)
{
    vis[v] = 1;
    cout << v << " ";
    for (int i = 0; i < G[v].size(); i++)
    {
        int p = G[v][i].first;
        if (vis[p])
            continue;
        dfs(p);
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
