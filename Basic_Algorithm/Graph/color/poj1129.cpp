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
#define N 30

typedef long long LL;

int n;
bool G[N][N];
int color;
int c[N];

bool ok(int v, int co)
{
    for (int i = 0; i < v; i++)
    {
        if (G[v][i] && c[i] == co)
            return false;
    }
    return true;
}

bool dfs(int num)
{
    if (num == n)
        return true;

    for (int i = 1; i <= color; i++)
    {
        if (ok(num, i))
        {
            c[num] = i;
            if (dfs(num + 1))
                return true;
            c[num] = 0;
        }
    }
    return false;
}

int main()
{
    while (cin >> n && n)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 2; j < s.size(); j++)
                G[s[0] - 'A'][s[j] - 'A'] = G[s[j] - 'A'][s[0] - 'A'] = 1;
        }

        for (color = 1; color <= 4; color++)
        {
            memset(c, 0, sizeof(c));
            if (dfs(0))
            {
                if (color == 1)
                    cout << "1 channel needed." << endl;
                else
                    cout << color << " channels needed." << endl;
                break;
            }
        }
    }
    return 0;
}
