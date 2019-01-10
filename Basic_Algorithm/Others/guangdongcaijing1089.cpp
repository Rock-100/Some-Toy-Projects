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

vector<int> line;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        line.clear();
        for (int i = 0; i < n; i++)
        {
            int l;
            scanf("%d", &l);
            line.push_back(l);
        }

        sort(line.begin(), line.end());
        int res = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            if (line[i] < line[i - 1] + line[i - 2])
            {
                res = line[i] + line[i- 1] + line[i - 2];
                break;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
