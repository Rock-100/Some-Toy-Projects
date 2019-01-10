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

#define N 10
int num[N];
bool used[N];

void permutation(int n, int cou = 0)
{
    if (cou == n)
    {
        for (int i = 0; i < n; i++)
            cout << num[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            num[cou] = i;
            used[i] = 1;
            permutation(n, cou + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    int n = 3;
    memset(used, 0, sizeof(used));
    permutation(n);
    return 0;
}

