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

int n, m;

int main()
{
    while (cin >> n >> m)
    {
        list<int> human;
        for (int i = 1; i <= n; i++)
            human.push_back(i);

        list<int>::iterator it = human.begin();
        int cou = 1;
        while (human.size() > 1)
        {
            if (cou == m)
                it = human.erase(it);
            else
                it++;
            cou++;

            if (cou > m) cou -= m;
            if (it == human.end()) it = human.begin();
        }

        cout << *human.begin() << endl;
    }
    return 0;
}
