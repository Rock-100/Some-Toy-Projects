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
#define MOD 10007

typedef long long LL;


int fastpower(int a, int b)
{
    if (!b)
        return 1;
    int ret = 1;
    if (b & 1)
        ret = a % MOD;
    int mul = fastpower(a, b >> 1);
    ret = ret * mul % MOD * mul % MOD;
    return ret;
}

int fastpower2(int a, int b)
{
    if (!b)
        return 1;
    a %= MOD;
    int ret = 1;
    if (b & 1)
        ret = a;
    return ret * fastpower2(a * a, b >> 1) % MOD;
}

int fastpower3(int a, int b)
{
    int ret = 1;
    while (b)
    {
        a %= MOD;
        if (b & 1)
            ret = ret * a % MOD;
        a *= a;
        b >>= 1;
    }
    return ret;
}


int main()
{
    cout << fastpower(300000,10000000)<< endl;
    cout << fastpower2(300000,10000000)<< endl;
    cout << fastpower3(300000,10000000)<< endl;

    return 0;
}
