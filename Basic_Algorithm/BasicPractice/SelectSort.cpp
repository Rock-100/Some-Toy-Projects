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


void SelectSort(int *mybegin, int *myend)
{
    int n = myend - mybegin;
    for (int i = 0; i < n - 1; i++)
    {
        pair<int, int> num;
        num.first = mybegin[i];
        num.second = i;

        for (int j = i + 1; j < n; j++)
        {
            if (mybegin[j] < num.first)
            {
                num.first = mybegin[j];
                num.second = j;
            }
        }
        swap(mybegin[i], mybegin[num.second]);
    }
}

int main()
{
    int num[5] = {1, 4, 5, 2, 7};
    int n = 5;

    SelectSort(num, num + n);

    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}
