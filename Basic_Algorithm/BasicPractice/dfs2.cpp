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

deque<Position> pos;
LL dfs(int x, int y)
{
    LL res = 0;
    bool flag = 0;
    for (int i = 0; i < 4; i++)
    {
        int s = x + dx[i], t = y + dy[i];
        if (legal(s, t) && !vis[s][t])
        {
            vis[s][t] = 1;
            pos.push_back(Position(s, t));
            res += dfs(s, t);
            pos.pop_back();
            vis[s][t] = 0;
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << "step: " << pos.size() - 1 << " ";
        for (int i = 0; i < pos.size(); i++)
            cout << "(" << pos[i].X << "," << pos[i].Y << ")";
        cout << endl;
        res = 1;
    }
    return res;
}

int main()
{
    vis[0][0] = 1;
    pos.push_back(Position(0, 0));
    cout << dfs(0, 0) << endl;
    return 0;
}
