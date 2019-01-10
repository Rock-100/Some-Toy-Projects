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

int gcd(int a, int b)
{
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    cout << gcd(8, 14) << " " << lcm(8, 14) << endl;
    cout << gcd(27, 18) << " " << lcm(27, 18) << endl;
    cout << gcd(7, 13) << " " << lcm(7, 13) << endl;

    return 0;
}
