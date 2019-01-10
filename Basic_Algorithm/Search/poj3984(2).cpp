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

#define N 10
#define INF (1<<30)

int n = 5;
bool garden[N][N];
bool vis[N][N];
pair<int, int> pre[N][N];
stack<pair<int, int> > ans;

bool legal(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return 1;
    else
        return 0;
}
int min_step;
int dfs(int r, int t, int step = 0)
{
    if (r == n - 1 && t == n - 1)
    {
        if (step < min_step)
        {
            min_step = step;
            while(!ans.empty())
                ans.pop();
            ans.push(make_pair(r, t));
            pair<int, int> p = pre[r][t];
            while (p.first + p.second != 0)
            {
                ans.push(p);
                p = pre[p.first][p.second];
            }
            ans.push(make_pair(0, 0));
        }
        return step;
    }

    int res = INF;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        {
            int s = r + dx, g = t + dy;
            if (dx * dy == 0 && dx + dy != 0 && legal(s, g) && !garden[s][g] && !vis[s][g])
            {
                vis[s][g] = 1;
                pre[s][g] = make_pair(r, t);
                res = min(res, dfs(s, g, step + 1));
                vis[s][g] = 0;
            }
        }

    return res;
}
int main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> garden[i][j];
    vis[0][0] = 1;
    min_step = INF;
    dfs(0, 0);
    while (ans.size())
    {
        cout << "(" << ans.top().first << ", " << ans.top().second << ")" << endl;
        ans.pop();
    }
    return 0;
}
