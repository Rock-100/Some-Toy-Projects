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
#define N 200

typedef long long LL;

int G[N][N];
bool used[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        while (cin >> t && t)
            G[t][i] = 1;
    }

    stack<int> ans;
    while (ans.size() < n)
    {
        for (int v = 1; v <= n; v++)
        {
            if (!used[v])
            {
                int degree = 0;
                for (int i = 1; i <= n; i++)
                    degree += G[i][v];
                if (!degree)
                {
                    ans.push(v);
                    used[v] = 1;
                    for (int i = 1; i <= n; i++)
                        G[i][v] = G[v][i] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int num = ans.top();
        ans.pop();
        if (i == n - 1)
            cout << num << endl;
        else
            cout << num << " ";
    }
    return 0;
}
