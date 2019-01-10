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
int num[N], n, k;

int Divide(int *num, int left, int right)
{
    int index = right - 1, key = num[right - 1];

    int pos = left - 1;
    bool flag = 0;
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

int find_k(int *num, int *numend, int k)
{
    int n = numend - num;
    int left = 0, right = n;

    while (left < right)
    {
        int mid = Divide(num, left, right);
        if (mid > k)
            right = mid;
        else if (mid < k)
            left = mid + 1;
        else
            break;
    }
    return num[k];
}
int main()
{

    while (scanf("%d%d", &n, &k) != EOF)
    {

        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        int res = find_k(num, num + n, k - 1);

        printf("%d\n", res);
    }

    return 0;
}
