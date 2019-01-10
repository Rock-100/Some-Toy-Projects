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

void create(list<int> &link, int num)
{
    for (int i = 0; i < num; i++)
        link.push_back(i);
}

void disp(list<int> &link)
{
    list<int>::iterator it;
    for (it = link.begin(); it != link.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void erase_ele(list<int> &link, int num)
{
    list<int>::iterator it;
    it = link.begin();
    while (num--)
        it++;
    link.erase(it);
}

void insert_ele(list<int> &link, int num, int va)
{
    list<int>::iterator it;
    it = link.begin();
    while (num--)
        it++;
    link.insert(it, va);
}

int main()
{
    list<int> link;
    create(link, 7);

    disp(link);

    erase_ele(link, 2);

    insert_ele(link, 4, 666);

    disp(link);

    link.clear();

    return 0;
}
