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
#define N 100010
#define val first
#define pos second

typedef long long LL;


int num[N];
int n, m;

pair<int, int> que[N];
int head, tail;

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        for (int i = 1; i <= n; i++)
            num[i] += num[i - 1];

        head = tail = 0;
        que[tail++] = make_pair(num[0], 0);
        int ans = num[1];
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, num[i] - que[head].val);
            while (head < tail && que[tail - 1].val > num[i])
                tail--;
            que[tail++] = make_pair(num[i], i);
            if (que[head].pos == i - m)
                head++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
