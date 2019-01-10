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

double dp[N][N];
double p[N][N][3];
int r, c;

int main()
{
    while (scanf("%d%d", &r, &c) != EOF)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                for (int k = 0; k < 3; k++)
                    scanf("%lf", &p[i][j][k]);
        for (int i = r - 1; i >= 0; i--)
            for (int j = c - 1; j >= 0; j--)
            {
                if (i == r - 1 && j == c - 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (1 - p[i][j][0] < eps) continue;
                dp[i][j] = (p[i][j][1] * dp[i][j + 1] + p[i][j][2] * dp[i + 1][j] + 2) / (1 - p[i][j][0]);
            }

        printf("%.3f\n", dp[0][0]);

    }
    return 0;
}

