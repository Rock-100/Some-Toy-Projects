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
    queue<int> qu;
    qu.push(3);
    qu.push(7);
    qu.push(4);

    cout << qu.front() << endl;

    qu.pop();

    cout << qu.front() << endl;

    return 0;
}
