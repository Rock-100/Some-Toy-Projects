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
#define N 100100

typedef long long LL;

int n;
int num[N];

int main()
{
    int cas;
    scanf("%d", &cas);
    for (int t = 1; t <= cas; t++)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        for (int i = 1; i <= n; i++)
            num[i] += num[i - 1];
        int ans = num[1], from = 1, to = 1;
        int mmin = num[0], pos = 0;
        for (int i = 1; i <= n; i++)
        {
            if (num[i] - mmin > ans)
            {
                ans = num[i] - mmin;
                to = i;
                from = pos + 1;
            }
            if (num[i] < mmin)
            {
                mmin = num[i];
                pos = i;
            }
        }
        printf("Case %d:\n", t);
        printf("%d %d %d\n", ans, from, to);
        if (cas != t)
            printf("\n");
    }

    return 0;
}
