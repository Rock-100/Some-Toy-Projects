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

int squ(int x)
{
    return x * x * x;
}

int dict[10000], n;

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            if (i * j)
            {
                int num = -a[0] * squ(i) - a[1] * squ(j);
                dict[n++] = num;
            }
    sort(dict, dict + n);
    LL res = 0;
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            for (int k = -50; k <= 50; k++)
                if (i * j * k)
                {
                    int num = a[2] * squ(i) + a[3] * squ(j) + a[4] * squ(k);
                    res += upper_bound(dict, dict + n, num) - lower_bound(dict, dict + n, num);
                }
    cout << res << endl;
    return 0;
}
