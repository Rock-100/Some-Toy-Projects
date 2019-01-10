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

int dp[N][N];

int main()
{
    string A, B;
    while (cin >> A >> B)
    {
        int n = A.size(), m = B.size();
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = A[0] == B[i] ? 1 : 0;
            dp[0][i] = max(dp[0][i], dp[0][i - 1]);
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i -1][j]);
            }
        }

        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}

