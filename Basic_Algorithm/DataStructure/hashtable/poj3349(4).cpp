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
#define MOD 500007
#define N 100010

typedef long long LL;

int n;
struct SNOW
{
    int f[6];
    int sum;
    int next;
};

SNOW snow[N];

bool same(int s, int t)
{
    for (int i = 0; i < 6; i++)
    {
        int a, b;
        bool flag = 1;
        for (int k = 0; k < 6; k++)
        {
            a = k, b = (k + i) % 6;
            if (snow[s].f[a] != snow[t].f[b])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
        flag = 1;
        for (int k = 0; k < 6; k++)
        {
            a = k, b = (i - k + 6) % 6;
            if (snow[s].f[a] != snow[t].f[b])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

int hashtable[MOD];

void insert_hash(int i)
{
    int id = snow[i].sum % MOD;
    snow[i].next = hashtable[id];
    hashtable[id] = i;
}

bool find_hash(int s)
{
    int id = snow[s].sum % MOD;
    int index = hashtable[id];
    while (index != 0)
    {
        if (same(index, s))
            return true;
        index = snow[index].next;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        snow[i].sum = 0;
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &snow[i].f[j]);
            snow[i].sum += snow[i].f[j];
        }

        if (find_hash(i))
            flag = 1;
        insert_hash(i);
    }

    if (flag)
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");

    return 0;
}
