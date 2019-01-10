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

int solve(int left, int right)
{
    if (left == right)
        return 0;

    int res = inf;
    for (int mid = left; mid < right; mid++)
    {
        int temp = solve(left, mid) + solve(mid + 1, right) + A[left].first * A[mid].second * A[right].second;
        if (res > temp)
        {
            res = temp;
            pos[left][right] = mid;
        }
    }

    return res;
}

void backtracking(int left, int right)
{
    if (right - left < 2)
        return;

    int mid = pos[left][right];
    cout << left << " " << mid << " " << right << endl;
    backtracking(left, mid);
    backtracking(mid + 1, right);

}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> A[i].first >> A[i].second;

        cout << solve(0, n - 1) << endl;
        backtracking(0, n - 1);
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
