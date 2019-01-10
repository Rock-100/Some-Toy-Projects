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

#define N 3
bool vis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool legal(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N)
        return 1;
    else
        return 0;
}
struct Position
{
    int X, Y;
    Position (int x = 0, int y = 0) : X(x), Y(y)
    {
    }
};

Position pre[N][N];
queue<Position> que;
LL bfs()
{
    vis[0][0] = 1;
    que.push(Position(0, 0));

    LL res = 0;
    while (que.size())
    {
        Position p = que.front();
        que.pop();
        bool flag = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = p.X + dx[i], y = p.Y + dy[i];
            if (legal(x, y) && !vis[x][y])
            {
                vis[x][y] = 1;
                pre[x][y] = Position(p.X, p.Y);
                que.push(Position(x, y));
                flag = 1;
            }
        }
        if (!flag)
        {
            stack<Position> ans;
            ans.push(p);
            p = pre[p.X][p.Y];
            while (p.X + p.Y != 0)
            {
                ans.push(p);
                p = pre[p.X][p.Y];
            }
            ans.push(Position(0, 0));
            cout << "step: " << ans.size() - 1 << " ";
            while (ans.size())
            {

                cout << "(" << ans.top().X << "," << ans.top().Y << ")";
                ans.pop();
            }
            cout << endl;
            res++;
        }
    }

    return res;
}

int main()
{
    cout << bfs() << endl;
    return 0;
}
