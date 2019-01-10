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

list<int> num;
int n, k;

int main()
{
    while (cin >> n)
    {
        num.clear();
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            num.push_back(t);
        }
        cin >> k;

        cout << num.size() << endl;
        for (list<int>::iterator it = num.begin(); it != num.end(); it++)
        {
            if (it == num.begin())
                cout << *it;
            else
                cout << " " << *it;
        }
        cout << endl;

        for (list<int>::iterator it = num.begin(); it != num.end();)
        {
            if (*it == k)
                it = num.erase(it);
            else
                it++;
        }

        cout << num.size() << endl;
        for (list<int>::iterator it = num.begin(); it != num.end(); it++)
        {
            if (it == num.begin())
                cout << *it;
            else
                cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
