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


int main()
{
    int n;
    int m, d;
    while (cin >> n)
    {
        queue<string> qu;
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            qu.push(st);
        }
        char c;
        cin >> m >> c >> d;
        for (int i = 1; i < m; i++)
        {
            qu.push(qu.front());
            qu.pop();
        }
        while (!qu.empty())
        {
            for (int i = 1; i < d; i++)
            {
                qu.push(qu.front());
                qu.pop();
            }
            cout << qu.front() << endl;
            qu.pop();
        }
    }
    return 0;
}
