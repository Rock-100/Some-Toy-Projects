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

void InsertSort(int *mybegin, int *myend)
{
    int n = myend - mybegin;
    for (int i = 1; i < n; i++)
    {
        int va = mybegin[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (va < mybegin[j])
                mybegin[j + 1] = mybegin[j];
            else
            {
                mybegin[j + 1] = va;
                break;
            }
        }
        if (j == -1)
            mybegin[0] = va;
    }
}

int main()
{
    int num[5] = {1, 4, 5, 2, 7};
    int n = 5;

    InsertSort(num, num + n);

    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}
