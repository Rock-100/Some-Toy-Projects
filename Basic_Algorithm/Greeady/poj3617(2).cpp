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
    cin >> n;
    string input;
    input.resize(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    int head = 0, tail = n - 1;
    string output;
    while (head <= tail)
    {
        bool left = 0;
        for (int L = head, R = tail; L < R; L++, R--)
        {
            if (input[L] < input[R])
            {
                left = 1;
                break;
            }
            if (input[L] > input[R])
            {
                break;
            }
        }
        if (left)
            output.push_back(input[head++]);
        else
            output.push_back(input[tail--]);
    }
    for (int i = 0; i < n;)
    {
        cout << output[i++];
        if (i % 80 == 0 && i != n)
            cout << endl;
    }
    return 0;
}
