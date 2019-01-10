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
#define N 1000
#define S 1000

typedef long long LL;

int va[N];
int num[N];
int dp[S];

int main()
{
    int n, sum;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> va[i] >> num[i];
    cin >> sum;

    fill(dp + 1, dp + sum + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[j] >= 0)
                dp[j] = num[i];
            else
            {
                if (j < va[i] || dp[j - va[i]] <= 0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j - va[i]] - 1;
            }
        }
    }


    cout << (dp[sum] >= 0) << endl;
    return 0;
}

/*
3
3 3
5 2
8 2
17
*/
