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
#define N 20010

typedef long long LL;

int n;
int heap[N];

void heaplify(int index)
{
    while (2 * index + 1 < n)
    {
        int pos = 2 * index + 1;
        int r = 2 * index + 2;

        if (r < n && heap[r] < heap[pos])
            pos = r;

        if (heap[pos] < heap[index])
        {
            swap(heap[pos], heap[index]);
            index = pos;
        }
        else
            break;
    }
}

void min_heap()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heaplify(i);
}

void push(int x)
{
    heap[n++] = x;
    int index = n - 1;

    while (index)
    {
        int fa = (index - 1) / 2;
        if (heap[fa] > heap[index])
        {
            swap(heap[fa], heap[index]);
            index = fa;
        }
        else
            break;
    }
}

void pop()
{
    heap[0] = heap[n - 1];
    n--;
    heaplify(0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &heap[i]);
    min_heap();

    LL res = 0;
    int m = n;
    for (int i = 0; i < m - 1; i++)
    {
        int L = 0;
        L += heap[0];
        pop();
        L += heap[0];
        pop();
        push(L);
        res += L;
    }
    printf("%I64d\n", res);
    return 0;
}
