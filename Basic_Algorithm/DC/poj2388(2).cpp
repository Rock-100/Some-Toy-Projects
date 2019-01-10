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

#define N 10010
int num[N], n;

int Divide(int *num, int *numend)
{
    int n = numend - num;
    int index = n - 1, key = num[n - 1];
    int *data = new int[n];
    int head = -1, tail = n;
    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] < key)
            data[++head] = num[i];
        else
            data[--tail] = num[i];
    }
    data[head + 1] = key;
    index = head + 1;
    for (int i = 0; i < n; i++)
        num[i] = data[i];
    delete [] data;
    return index;
}

void QuickSort(int *num, int *numend)
{
    int n = numend - num;

    if (n > 1)
    {
        int mid = Divide(num, numend);
        QuickSort(num, num + mid);
        QuickSort(num + mid + 1, num + n);
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        QuickSort(num, num + n);

        printf("%d\n", num[n >> 1]);
    }

    return 0;
}
