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

typedef long long LL;

#define N 8
bool chessboard[N][N];

bool check(int i, int j)
{
    for (int k = 0; k < N; k++)
        if (chessboard[i][k] && k != j)
            return 0;

    for (int k = 1;  i + k < N && j + k < N; k++)
        if (chessboard[i + k][j + k])
            return 0;

    for (int k = 1;  i + k < N && j - k >= 0; k++)
        if (chessboard[i + k][j - k])
            return 0;

    for (int k = 1;  i - k >= 0 && j - k >= 0; k++)
        if (chessboard[i - k][j - k])
            return 0;

    for (int k = 1;  i - k >= 0 && j + k < N; k++)
        if (chessboard[i - k][j + k])
            return 0;

    return 1;
}

int dfs(int num = 0)
{
    if (num == N)
    {
        return 1;
    }
    else
    {
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            if (!check(i, num))
                continue;
            chessboard[i][num] = 1;
            res += dfs(num + 1);
            chessboard[i][num] = 0;
        }
        return res;
    }
}

int main()
{
    cout << "Solution: " << dfs() << endl;
    return 0;
}
