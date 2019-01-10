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

struct Position
{
    int X, Y;
    Position (int x = 0, int y = 0) : X(x), Y(y)
    {
    }
};

Position ori, des;

bool legal(int x, int y)
{
    if (x >= 0 && x <= 300 && y >= 0 && y <= 300)
        return 1;
    else
        return 0;
}

#define N 350
bool vis[N][N];
int step[N][N];
Position que[N * N];
int head, tail;
int dx[10] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[10] = {-2, 2, -2, 2, -1, 1, -1, 1};

int bfs()
{
    step[ori.X][ori.Y] = 0;
    vis[ori.X][ori.Y] = 1;
    head = tail = 0;
    que[tail++] = ori;

    while (head < tail)
    {
        Position p = que[head];
        head++;

        for (int i = 0; i < 8; i++)
        {
            int s = p.X + dx[i], t = p.Y + dy[i];
            if (legal(s, t) && !vis[s][t])
            {
                step[s][t] = step[p.X][p.Y] + 1;
                vis[s][t] = 1;
                que[tail++] = Position(s, t);
            }
        }
    }
    return step[des.X][des.Y];
}

int main()
{
    while (cin >> ori.X >> ori.Y >> des.X >> des.Y)
    {
        memset(vis, 0, sizeof(vis));
        cout << bfs() << endl;
    }
    return 0;
}
