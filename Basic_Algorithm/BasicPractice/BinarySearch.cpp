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


int BinarySearch(int *num, int *numend, int key)
{
    int n = numend - num;
    int low = 0, high = n;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (num[mid] == key)
            return mid;
        else if(num[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return -1;
}

int BinarySearch2(int *num, int *numend, int key)
{
    int n = numend - num;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (num[mid] == key)
            return mid;
        else if(num[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int BinarySearch3(int *num, int *numend, int key)
{
    int n = numend - num;
    int low = 0, high = n;
    if (low < high)
    {
        int mid = (low + high) >> 1;
        if (num[mid] == key)
            return mid;
        else if(num[mid] < key)
            return BinarySearch3(num + mid + 1, num + high, key);
        else
            return BinarySearch3(num + low, num + mid, key);
    }
    return -1;
}

int main()
{
    int num[10] = {1, 4, 5, 2, 7, 5, 9};
    int n = 7;

    sort(num, num + n);
    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;

    cout << BinarySearch(num, num + n, 1) << endl;
    cout << BinarySearch(num, num + n, 5) << endl;
    cout << BinarySearch(num, num + n, 2) << endl;
    cout << BinarySearch(num, num + n, 3) << endl;

    cout << BinarySearch2(num, num + n, 1) << endl;
    cout << BinarySearch2(num, num + n, 5) << endl;
    cout << BinarySearch2(num, num + n, 2) << endl;
    cout << BinarySearch2(num, num + n, 3) << endl;

    cout << BinarySearch3(num, num + n, 1) << endl;
    cout << BinarySearch3(num, num + n, 5) << endl;
    cout << BinarySearch3(num, num + n, 2) << endl;
    cout << BinarySearch3(num, num + n, 3) << endl;

    cout << binary_search(num, num + n, 1) << endl;
    cout << binary_search(num, num + n, 5) << endl;
    cout << binary_search(num, num + n, 2) << endl;
    cout << binary_search(num, num + n, 3) << endl;

    return 0;
}
