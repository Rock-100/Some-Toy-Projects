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
#define N 10100

typedef long long LL;

int divide(int *num, int *numend)
{
    int n = numend - num;
    int index = n - 1, key = num[n - 1];

    int pos = -1;
    bool flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] < key)
        {
            pos++;
            if (i != pos)
                swap(num[i], num[pos]);
        }
        else if (num[i] == key)
        {
            if (flag)
            {
                pos++;
                if (i != pos)
                    swap(num[i], num[pos]);
            }
            flag = !flag;
        }
    }
    swap(num[pos + 1], num[index]);
    index = pos + 1;
    return index;
}


void mysort(int *num, int *numend)
{
    int n = numend - num;
    if (n > 1)
    {
        int mid = divide(num, num + n);
        mysort(num, num + mid);
        mysort(num + mid + 1, num + n);
    }
}

int num[N];

int myupper_bound(int *num, int *numend, int key)
{
    int n = numend - num;
    if (key >= num[n - 1]) return -1;

    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (num[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }

    return num[low];
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> num[i];
        mysort(num, num + n);
        while (m--)
        {
            int k;
            cin >> k;
            int res = myupper_bound(num, num + n, k - 1);
            cout << res << endl;
        }
    }
    return 0;
}

