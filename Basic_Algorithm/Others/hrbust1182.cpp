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
    while (cin >> n)
    {
        int cou = 1;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (num >= cou)
            {
                while (cou < num)
                    st.push(cou++);
                cou = num + 1;
            }
            else
            {
                if (!st.empty() && st.top() == num)
                    st.pop();
            }
        }

        if (st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
