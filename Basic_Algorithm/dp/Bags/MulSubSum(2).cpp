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
bool dp[S];

int main()
{
    int n, sum;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> va[i] >> num[i];
    cin >> sum;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= va[i]; j--)
        {
            int k = 1;
            while (k <= num[i] && k * va[i] <= j)
            {
                dp[j] |= dp[j - k * va[i]];
                k++;
            }
        }
    }

    cout << dp[sum] << endl;

    return 0;
}

/*
3
3 3
5 2
8 2
17
*/
