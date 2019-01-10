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

struct LINK
{
    int data;
    LINK *next;
};

void create(LINK *&lis, int num)
{
    LINK *p, *q;
    for (int i = 0; i < num; i++)
    {
        p = new LINK;
        p->data = i;
        p->next = NULL;
        if (!lis)
            lis = p;
        else
            q->next = p;
        q = p;
    }
}

void disp(LINK *&lis)
{
    LINK *p, *q;
    for (p = lis; p != NULL; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

void erase_ele(LINK *&lis, int num)
{
    LINK *p, *q;
    p = lis;
    while (num--)
        p = p->next;
    for (q = lis; q->next != p; q = q->next);
    q->next = p->next;
    delete p;
}

void insert_ele(LINK *&lis, int num, int va)
{
    LINK *p, *q;
    p = lis;
    while (num--)
        p = p->next;
    for (q = lis; q->next != p; q = q->next);
    LINK *temp = new LINK;
    temp->data = va;
    temp->next = p;
    q->next = temp;
}

void destory(LINK *&lis)
{
    LINK *p, *q;
    for (p = lis; p != NULL; )
    {
        q = p;
        p = p->next;
        delete q;
    }
    lis = NULL;
}

int main()
{
    LINK *lis = NULL;

    create(lis, 7);

    disp(lis);

    erase_ele(lis, 2);

    insert_ele(lis, 4, 666);

    disp(lis);

    destory(lis);

    return 0;
}
