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
int n = 5;
bool garden[N][N];
int step[N][N];
pair<int, int> pre[N][N];

bool legal(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return 1;
    else
        return 0;
}

queue<pair<int, int> > que;
int bfs()
{
    que.push(make_pair(0, 0));
    garden[0][0] = 1;
    memset(step, 0, sizeof(step));
    while (!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();

        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
            {
                int s = p.first + dx, t = p.second + dy;
                if (!(dx * dy) && legal(s, t) && !garden[s][t])
                {
                    que.push(make_pair(s, t));
                    garden[s][t] = 1;
                    step[s][t] = step[p.first][p.second] + 1;
                    pre[s][t] = make_pair(p.first, p.second);
                    if (s == n - 1 && t == n - 1)
                        return step[s][t];
                }
            }
    }
}

int main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> garden[i][j];
    bfs();
    stack<pair<int, int> > ans;
    pair<int, int> p = pre[n - 1][n - 1];
    ans.push(make_pair(n - 1, n - 1));
    while (p.first + p.second)
    {
        ans.push(p);
        p = pre[p.first][p.second];
    }
    ans.push(make_pair(0, 0));

    while (ans.size())
    {
        cout << "(" << ans.top().first << ", " << ans.top().second << ")" << endl;
        ans.pop();
    }
    return 0;
}
