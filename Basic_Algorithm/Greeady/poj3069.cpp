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
#define N 1010

typedef long long LL;

int r, n;
int pos[N];

int main()
{
    while (cin >> r >> n && r >= 0)
    {
        for (int i = 0; i < n; i++)
            cin >> pos[i];
        sort(pos, pos + n);
        int res = 0;
        int num = 0;
        while (num < n)
        {
            int p = pos[num];
            while (num < n && pos[num] - p <= r)
                num++;
            p = pos[num - 1];
            while (num < n && pos[num] - p <= r)
                num++;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
