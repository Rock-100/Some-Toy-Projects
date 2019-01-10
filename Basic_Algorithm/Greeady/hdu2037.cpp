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

typedef long long LL;


int n;
pair<int, int> program[N];
int dp[N];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}


int main()
{
    while (cin >> n && n)
    {

        for (int i = 0; i < n; i++)
            cin >> program[i].first >> program[i].second;

        sort(program, program + n, cmp);

        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            int pre = i - 1;
            while (pre >= 0 && program[pre].second > program[i].first)
                pre--;
            if (pre >= 0)
                dp[i] = max(dp[i], dp[pre] + 1);
        }

        cout << dp[n - 1] << endl;
    }


    return 0;
}
