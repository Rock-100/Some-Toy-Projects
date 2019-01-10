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


int main()
{
    int n;
    int m, d;
    while (cin >> n)
    {
        list<string> ls;
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            ls.push_back(st);
        }
        char c;
        cin >> m >> c >> d;
        list<string>::iterator it = ls.begin();
        for (int i = 1; i < m; i++)
        {
            it++;
            if (it == ls.end()) it = ls.begin();
        }
        while (ls.size())
        {
            for (int i = 1; i < d; i++)
            {
                it++;
                if (it == ls.end()) it = ls.begin();
            }
            cout << *it << endl;
            it = ls.erase(it);
            if (it == ls.end()) it = ls.begin();
        }
    }
    return 0;
}

