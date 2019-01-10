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
#define inf (1<<30)
#define N 50

typedef long long LL;
typedef pair<int, int> Matrix;

Matrix A[N];
int n;
int pos[N][N];
int dp[N][N];

string backtracking(int left, int right)
{
    if (right - left < 2)
    {
        string s;
        for (int i = left; i <= right; i++)
            s.push_back(i + '0');
        return s;
    }

    int mid = pos[left][right];
    string s1 = backtracking(left, mid);
    string s2 = backtracking(mid + 1, right);
    string s;
    if (mid - left > 0)
    {
        if (right - mid > 1)
            s = "(" + s1 + ")(" + s2 + ")";
        else
            s = "(" + s1 + ")" + s2;
    }
    else
    {
        if (right - mid > 1)
            s = s1 + "(" + s2 + ")";
        else
            s = s1 + s2;
    }
    return s;
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> A[i].first >> A[i].second;

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for (int len = 1; len < n; len++)
        {
            for (int left = 0, right = len; right < n; left++, right++)
            {
                dp[left][right] = inf;
                for (int mid = left; mid < right; mid++)
                {
                    int temp = dp[left][mid] + dp[mid + 1][right] + A[left].first * A[mid].second * A[right].second;
                    if (temp < dp[left][right])
                    {
                        dp[left][right] = temp;
                        pos[left][right] = mid;
                    }
                }
            }
        }

        cout << dp[0][n - 1] << endl;
        cout << backtracking(0, n - 1) << endl;
    }
    return 0;
}

/*
6
2 3
3 4
4 2
2 7
7 9
9 3
*/
