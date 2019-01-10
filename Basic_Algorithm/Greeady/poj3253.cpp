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
int length[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &length[i]);
    LL res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (length[i] > length[i + 1])
            swap(length[i], length[i + 1]);

        for (int j = i + 2; j < n; j++)
        {
            if (length[j] < length[i])
            {
                swap(length[i], length[j]);
                swap(length[i + 1], length[j]);
            }
            else if (length[j] < length[i + 1])
            {
                swap(length[i + 1], length[j]);
            }
        }
        length[i + 1] = length[i] + length[i + 1];
        res += length[i + 1];
    }
    printf("%I64d\n", res);
    return 0;
}
