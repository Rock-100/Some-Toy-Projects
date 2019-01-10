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


int find_k(int *num, int *numend, int k)
{
    int n = numend - num;
    int left = 0, right = n;


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
