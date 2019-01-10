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
    int st[10];
    int tail = 0;

    st[tail++] = 3;
    st[tail++] = 7;
    st[tail++] = 4;

    cout << st[tail - 1] << endl;

    tail--;

    cout << st[tail - 1] << endl;

    return 0;
}
