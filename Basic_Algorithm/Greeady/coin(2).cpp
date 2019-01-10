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
#define N 200

typedef long long LL;


int n = 117;

int main()
{

    int coin[3] = {10, 5, 1};
    int choice[3];
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        res += n / coin[i];
        choice[i] = n / coin[i];
        n %= coin[i];
    }
    cout << res << endl;
    for (int i = 0; i < 3; i++)
        cout << choice[i] << " ";

    return 0;
}
