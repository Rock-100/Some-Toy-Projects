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
priority_queue<int, vector<int>, greater<int> > length;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        length.push(temp);
    }

    LL res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int L = 0;
        L += length.top();
        length.pop();
        L += length.top();
        length.pop();
        length.push(L);
        res += L;
    }
    printf("%I64d\n", res);
    return 0;
}
