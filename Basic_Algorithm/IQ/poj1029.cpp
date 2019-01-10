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

#define N 1010
int n, k;
struct OCCUR
{
    int equ, left, right;
};
OCCUR occur[N];
int tmp[N];

int main()
{
    while (cin >> n >> k)
    {
        memset(occur, 0, sizeof(occur));
        int unequ_num = 0;
        while (k--)
        {
            int p;
            cin >> p;
            for (int i = 0; i < 2 * p; i++)
                cin >> tmp[i];
            char symbol;
            cin >> symbol;
            if (symbol == '=')
            {
                for (int i = 0; i < 2 * p; i++)
                    occur[tmp[i]].equ++;
            }
            else if (symbol == '<')
            {
                unequ_num++;
                for (int i = 0; i < p; i++)
                    occur[tmp[i]].left++;
                for (int i = p; i < 2 * p; i++)
                    occur[tmp[i]].right++;
            }
            else
            {
                unequ_num++;
                for (int i = 0; i < p; i++)
                    occur[tmp[i]].right++;
                for (int i = p; i < 2 * p; i++)
                    occur[tmp[i]].left++;
            }
        }

        int res, num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!occur[i].equ && ((!occur[i].left && occur[i].right == unequ_num) || (!occur[i].right && occur[i].left == unequ_num)))
            {
                res = i;
                num++;
            }
        }
        if (num > 1) res = 0;
        cout << res << endl;
    }
    return 0;
}
