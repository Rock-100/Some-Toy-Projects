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

#define N 1000010
int num[N], n;


int Divide(int *num, int left, int right)
{
    int index = right - 1, key = num[right - 1];
    int pos = left - 1;
    bool flag = 1;
    for (int i = left; i < right - 1; i++)
    {
        if (num[i] < key)
        {
            pos++;
            if (pos != i)
                swap(num[pos], num[i]);
        }
        else if (num[i] == key)
        {
            if (flag)
            {
                pos++;
                if (pos != i)
                    swap(num[pos], num[i]);
            }
            flag = !flag;
        }
    }
    swap(num[pos + 1], num[index]);
    index = pos + 1;
    return index;
}

int find_middle(int *num, int *numend)
{
    int n = numend - num;
    int left = 0, right = n;
    int des = n >> 1;

    while (left < right)
    {
        int mid = Divide(num, left, right);
        if (mid < des)
            left = mid + 1;
        else if (mid > des)
            right = mid;
        else
            break;
    }

    return num[des];
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        int res = find_middle(num, num + n);

        printf("%d\n", res);
    }

    return 0;
}
