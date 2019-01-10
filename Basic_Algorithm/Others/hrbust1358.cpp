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

#define N 100010
char input[N];


int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%s", input);
        string text(input);
        char key = '.';
        vector<string> patch;
        int beg = 0, len = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] != key)
                len++;
            else
            {
                patch.push_back(text.substr(beg, len));
                beg = i + 1, len = 0;
            }
        }
        patch.push_back(text.substr(beg, len));

        int n = patch.size();
        bool flag = 1;
        if (n < 2)
            flag = 0;
        else
        {
            if (patch[0].size() == 0 || patch[0].size() > 8) flag = 0;
            if (patch[n - 1].size() == 0 || patch[n - 1].size() > 3) flag = 0;
            for (int i = 1; i < n - 1; i++)
                if (patch[i].size() < 2 || patch[i].size() > 11) flag = 0;
        }

        if (flag)
        {
            printf("YES\n");
            for (int i = 1; i < n; i++)
            {
                int l = patch[i].size();
                if (i != n - 1)
                {
                    if (l == 2) l = 1;
                    else if (l == 3) l = 2;
                    else l = 3;
                }

                string dis;
                dis = patch[i - 1] + key + patch[i].substr(0, l);
                printf("%s\n", dis.c_str());
                patch[i].erase(patch[i].begin(), patch[i].begin() + l);
            }
        }
        else
            printf("NO\n");

    }

    return 0;
}
