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

struct ST
{
    int x, y;
    ST (int _x, int _y):x(_x), y(_y)
    {
    }
};

bool operator < (ST a, ST b)
{
    return a.x > b.x;
}

int main()
{
    priority_queue<ST> pq;
    int n = 10;
    for (int i = 0; i < n; i++)
        pq.push(ST(i, n - i));

    while(!pq.empty())
    {
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }

    return 0;
}
