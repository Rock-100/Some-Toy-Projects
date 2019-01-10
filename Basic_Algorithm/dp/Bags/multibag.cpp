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

typedef long long LL;

int dp[N];
int weight[N];
int value[N];
int num[N];

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i] >> num[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= weight[i]; j--)
        {
            for (int k = 1; k <= num[i] && k * value[i] <= j; k++)
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
        }
    }

    cout << dp[w] << endl;
    return 0;
}

/*
3 9
3 4 2
4 5 1
2 3 2
*/
