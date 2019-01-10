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

int n, m;

int main()
{
    while (cin >> n >> m)
    {
        queue<int> qu;
        for (int i = 1; i <= n; i++)
            qu.push(i);

        while (qu.size() != 1)
        {
            for (int i = 1; i < m; i++)
            {
                qu.push(qu.front());
                qu.pop();
            }
            qu.pop();
        }

        cout << qu.front() << endl;
    }
    return 0;
}
