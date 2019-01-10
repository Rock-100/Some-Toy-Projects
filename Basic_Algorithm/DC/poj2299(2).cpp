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

void Merge(int *num, int *nummid, int *numend)
{
    int mid = nummid - num;
    int n = numend - num;

    int *L = new int[mid];
    int *R = new int[n - mid];
    for (int i = 0; i < mid; i++)
        L[i] = num[i];
    for (int i = 0; i < n - mid; i++)
        R[i] = num[i + mid];

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (L[i] > R[j])
        {
            j++;
            res += mid - i;
        }
        else
            i++;
    }
    i = 0, j = 0;
    while (i < mid && j < n - mid)
    {
        if (L[i] > R[j])
            num[k++] = R[j++];
        else
            num[k++] = L[i++];
    }
    while (i < mid)
        num[k++] = L[i++];
    while (j < n - mid)
        num[k++] = R[j++];

    delete [] L;
    delete [] R;

}

void MergeSort(int *num, int *numend)
{
    int n = numend - num;

    if (n > 1)
    {
        int mid = n >> 1;
        MergeSort(num, num + mid);
        MergeSort(num + mid, num + n);
        Merge(num, num + mid, num + n);
    }
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        res = 0;
        MergeSort(num, num + n);
        printf("%I64d\n", res);
    }

    return 0;
}
