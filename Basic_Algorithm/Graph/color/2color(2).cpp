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
int color[N];
int n, m;

bool bfs()
{
    queue<int> qu;
    qu.push(0);
    color[0] = 1;

    while (qu.size())
    {
        int v = qu.front();
        qu.pop();
        int c = color[v];

        for (int i = 0; i < n; i++)
        {
            if (G[v][i])
            {
                if (color[i] == c)
                    return false;
                else if (!color[i])
                {
                    qu.push(i);
                    color[i] = -c;
                }
            }
        }
    }
    return true;
}

int main()
{
    while (cin >> n >> m)
    {
        memset(G, 0, sizeof(G));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < m; i++)
        {
            int s, t;
            cin >> s >> t;
            G[s][t] = G[t][s] = 1;
        }
        cout << bfs() << endl;
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

4 4
0 1
0 3
1 3
1 2

*/
