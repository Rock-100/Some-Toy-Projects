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
    int qu[10];
    int head = 0, tail = 0;

    qu[tail++] = 3;
    qu[tail++] = 7;
    qu[tail++] = 4;

    cout << qu[head] << endl;

    head++;

    cout << qu[head] << endl;

    return 0;
}
