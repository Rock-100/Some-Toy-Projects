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

#define N 110
int n, m;
char garden[N][N];
int index[N][N];
int total;

int dir[8][2]= { 1,1,
                 1,0,
                 1,-1,
                 -1,1,
                 -1,0,
                 -1,-1,
                 0,1,
                 0,-1
               };
bool legal(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return 1;
    else
        return 0;
}



void dfs(int i, int j)
{
    index[i][j] = total;

    for (int k = 0; k < 8; k++)
    {
        int s = i + dir[k][0], t = j + dir[k][1];
        if (legal(s, t) && garden[s][t] == 'W' && !index[s][t])
            dfs(s, t);
    }
}

queue<pair<int, int> > que;
void bfs(int i, int j)
{
    index[i][j] = total;
    que.push(make_pair(i, j));

    while (!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();

        for (int k = 0; k < 8; k++)
        {
            int s = p.first + dir[k][0], t = p.second + dir[k][1];
            if (legal(s, t) && garden[s][t] == 'W' && !index[s][t])
            {
                index[s][t] = total;
                que.push(make_pair(s, t));
            }
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> garden[i];

        memset(index, 0, sizeof(index));
        total = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (garden[i][j] == 'W' && !index[i][j])
                {
                    total++;
                    bfs(i, j);
                }
            }
        cout << total << endl;
    }

    return 0;
}
