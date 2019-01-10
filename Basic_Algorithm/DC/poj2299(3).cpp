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

#define N 500100
int num[N], n;
LL res;


int Divide(int *num, int *numend)
{
    int n = numend - num;
    int index = n - 1, key = num[n - 1];

    int *L = new int[n], *R = new int[n];
    int lhead = -1, rhead = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] < key)
        {
            L[++lhead] = num[i];
            res += rhead + 1;
        }
        else
        {
            res++;
            R[++rhead] = num[i];
        }
    }
    for (int i = 0; i <= lhead; i++)
        num[i] = L[i];
    num[lhead + 1] = key;
    index = lhead + 1;
    for (int i = 0; i <= rhead; i++)
        num[i + lhead + 2] = R[i];

    delete [] L;
    delete [] R;
    return index;
}

void QuickSort(int *num, int *numend)
{
    int n = numend - num;

    if (n > 1)
    {
        int mid = Divide(num, numend);
        QuickSort(num, num + mid);
        QuickSort(num + mid + 1, numend);
    }
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        res = 0;
        QuickSort(num, num + n);
        printf("%I64d\n", res);
    }

    return 0;
}
