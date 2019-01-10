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

char lef[3] = {'(', '[', '{'};
char rig[3] = {')', ']', '}'};

int main()
{
    string str;
    while (getline(cin, str))
    {
        stack<char> brac;
        bool flag = 1;
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (str[i] == lef[j])
                    brac.push(str[i]);
                if (str[i] == rig[j])
                {
                    if (!brac.empty() && brac.top() == lef[j])
                        brac.pop();
                    else
                        flag = 0;
                }
            }
        }
        if (brac.empty() && flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
