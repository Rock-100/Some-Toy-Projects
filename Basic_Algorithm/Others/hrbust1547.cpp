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

int main()
{
    for (int i = 2; i < 40000; i++)
        num.push_back(i);
    list<int>::iterator it = num.begin();
    while (it != num.end())
    {
        int luck = *it;
        int cou = 1;
        list<int>::iterator temp = it;
        temp++;
        while (temp != num.end())
        {
            if (cou % luck == 0)
                temp = num.erase(temp);
            else
                temp++;
            cou++;
        }
        it++;
    }
    int n;
    while (cin >> n)
    {
        list<int>::iterator it = num.begin();
        while (--n)
            it++;
        cout << *it << endl;
    }
    return 0;
}
