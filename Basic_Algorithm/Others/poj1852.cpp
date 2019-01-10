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
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int l, n;
        scanf("%d%d", &l, &n);
        int res_min = 0, res_max = 0;
        for (int i = 0; i < n; i++)
        {
            int dis;
            scanf("%d", &dis);
            res_min = max(res_min, min(dis, l - dis));
            res_max = max(res_max, max(dis, l - dis));
        }
        printf("%d %d\n", res_min, res_max);
    }

    return 0;
}
