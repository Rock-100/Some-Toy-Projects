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

vector<int> num;
int n;

int main()
{
    while (cin >> n)
    {
        num.clear();
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            int j;
            for (j = 0; j < num.size(); j++)
                if (num[j] == t)
                    break;
            if (j == num.size())
                num.push_back(t);

        }
        cout << num.size() << endl;
        for (int j = 0; j < num.size(); j++)
        {
            if (j == num.size() - 1)
                cout << num[j] << endl;
            else
                cout << num[j] << " ";
        }
    }
    return 0;
}
