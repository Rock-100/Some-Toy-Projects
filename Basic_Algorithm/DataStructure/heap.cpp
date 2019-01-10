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
#define N 1000

typedef long long LL;

void print(vector<int> num)
{
    for (int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
}

int main()
{
    int n = 10;
    vector<int> num;
    for (int i = 0; i < n; i++)
        num.push_back(n - i);

    make_heap(num.begin(), num.end());
    print(num);

    make_heap(num.begin(), num.end(), greater<int>());
    print(num);

    pop_heap(num.begin(), num.end(), greater<int>());
    num.pop_back();
    print(num);

    num.push_back(-1);
    push_heap(num.begin(), num.end(), greater<int>());
    print(num);

    sort_heap(num.begin(), num.end(), greater<int>());
    print(num);

    return 0;
}
