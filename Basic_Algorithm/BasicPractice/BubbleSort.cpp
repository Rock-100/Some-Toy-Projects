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

void BubbleSort(int *mybegin, int *myend)
{
    int n = myend - mybegin;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (mybegin[j] < mybegin[j - 1])
                swap(mybegin[j], mybegin[j - 1]);
        }
    }
}

int main()
{
    int num[5] = {1, 4, 5, 2, 7};
    int n = 5;

    BubbleSort(num, num + n);

    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}
