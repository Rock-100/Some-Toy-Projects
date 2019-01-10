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


        int res = 1;
        int time = program[0].second;

        for (int i = 1; i < n; i++)
        {
            if (program[i].first >= time)
            {
                res++;
                time = program[i].second;
            }
        }

        cout << res << endl;
    }


    return 0;
}
