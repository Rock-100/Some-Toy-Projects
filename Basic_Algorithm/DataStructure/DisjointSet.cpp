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
#define N 1000

typedef long long LL;

int fa[N], n;

void init()
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
}

int getfa(int x)
{
    if (x == fa[x])
        return x;
    else
    {
        fa[x] = getfa(fa[x]);
        return fa[x];
    }
}

bool isjoint(int x, int y)
{
    x = getfa(x);
    y = getfa(y);
    return x == y;
}

void mergefa(int x, int y)
{
    x = getfa(x);
    y = getfa(y);
    fa[x] = y;
}

void print()
{
    for (int i = 0; i < n; i++)
        cout << fa[i] << " ";
    cout << endl;
}

int main()
{
    n = 10;
    init();
    mergefa(2, 5);
    mergefa(9, 5);
    mergefa(3, 7);

    cout << isjoint(2, 9) << endl;

    print();

    return 0;
}
