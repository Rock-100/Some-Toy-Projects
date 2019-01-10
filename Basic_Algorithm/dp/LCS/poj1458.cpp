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

string A, B;
int dp[N][N];

int main()
{
    while (cin >> A >> B)
    {
        bool flag = 0;
        for (int i = 0; i < B.size(); i++)
        {
            if (A[0] == B[i])
                flag = 1;
            dp[0][i] = flag;
        }
        flag = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == B[0])
                flag = 1;
            dp[i][0] = flag;
        }

        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 1; j < B.size(); j++)
            {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[A.size() - 1][B.size() - 1] << endl;
    }
    return 0;
}

