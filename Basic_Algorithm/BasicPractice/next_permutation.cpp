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
    int num[4] = {3, 3, 1, 7};
    sort(num, num + 4);
    do
    {
        cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
    }
    while(next_permutation(num, num + 4));
    cout << "after:" << endl;
    cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
    return 0;
}

