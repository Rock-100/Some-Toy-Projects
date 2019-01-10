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
#define N 10010

typedef long long LL;

int n, L, P;
struct ST
{
    int dis, fu;
};
ST stop[N];

bool cmp(ST a, ST b)
{
    return a.dis < b.dis;
}

priority_queue<int> pq;


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stop[i].dis >> stop[i].fu;
    cin >> L >> P;

    for (int i = 0; i < n; i++)
        stop[i].dis = L - stop[i].dis;
    sort(stop, stop + n, cmp);
    stop[n].dis = L - stop[n - 1].dis;
    for (int i = n - 1; i >= 1; i--)
        stop[i].dis = stop[i].dis - stop[i - 1].dis;

    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        P -= stop[i].dis;

        while (P < 0 && pq.size())
        {
            P += pq.top();
            res++;
            pq.pop();
        }
        if (P < 0)
        {
            res = -1;
            break;
        }
        if (i < n)
            pq.push(stop[i].fu);
    }
    cout << res << endl;
    return 0;
}
