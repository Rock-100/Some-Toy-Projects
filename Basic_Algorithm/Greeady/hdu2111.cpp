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
#define N 200
#define value first
#define volume second

typedef long long LL;


int V, n;
pair<int, int> item[N];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.value > y.value;
}

int main()
{
    while (cin >> V && V)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> item[i].value >> item[i].volume;
        sort(item, item + n, cmp);

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (V >= item[i].volume)
            {
                res += item[i].value * item[i].volume;
                V -= item[i].volume;
            }
            else
            {
                res += V * item[i].value;
                V = 0;
            }
            if (!V) break;
        }
        cout << res << endl;
    }


    return 0;
}
