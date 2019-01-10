#include <iostream>
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

#define N 600
int card[N];
int twocard[N * N];

int binsearch(int *num, int *numend, int key)
{
    int n = numend - num;
    int low = 0, high = n;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (num[mid] == key)
            return mid;
        else if (num[mid] > key)
            high = mid;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &card[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                twocard[i * n + j] = card[i] + card[j];

        sort(twocard, twocard + n * n);
        int sta = -1;
        for (int i = 0; i < n * n; i++)
        {
            sta = binsearch(twocard, twocard + n * n, m - twocard[i]);
            if (sta != -1)
                break;
        }

        if (sta == -1)
            printf("No.\n");
        else
            printf("Yes.\n");
    }

    return 0;
}
