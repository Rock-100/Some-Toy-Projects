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
    priority_queue<int, vector<int>, greater<int> > pq;
    int n = 10;
    for (int i = 0; i < n; i++)
        pq.push(n - i);
    cout << pq.top() << endl;

    pq.pop();
    cout << pq.top() << endl;

    return 0;
}
