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

int n;
int num[N];
LL dp[N];

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> num[i];
        LL res = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = num[i];
            for (int j = 0; j < i; j++)
            {
                if (num[j] < num[i])
                    dp[i] = max(dp[i], dp[j] + num[i]);
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;

    }
    return 0;
}

