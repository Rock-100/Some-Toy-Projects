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

bool dfs(vector<int> &num, int &k, int step = 0, int sum = 0)
{
    if (step == num.size())
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }

    bool sta1 = dfs(num, k, step + 1, sum + num[step]);
    bool sta2 = dfs(num, k, step + 1, sum);

    if (sta1 ||  sta2)
        return 1;
    else
        return 0;
}

int main()
{
    int n, k;
    vector<int> num;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    if (dfs(num, k))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

/*
4 13
1 2 4 7

4 15
1 2 4 7
*/
