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
#define N 200
#define inf 1000000

typedef long long LL;


int n = 30;
int dp[N];
int choice[N];

int main()
{
    int coin[3] = {25, 10, 1};
    for (int i = 1; i <= n; i++)
    {
        dp[i] = inf;
        for (int j = 0; j < 3; j++)
        {
            if (i >= coin[j] && dp[i] > dp[i - coin[j]] + 1)
            {

                dp[i] = dp[i - coin[j]] + 1;
                choice[i] = coin[j];
            }
        }

    }

    cout << dp[n] << endl;
    if (dp[n] != inf)
        while (n)
        {
            cout << choice[n] << " ";
            n -= choice[n];
        }

    return 0;
}
