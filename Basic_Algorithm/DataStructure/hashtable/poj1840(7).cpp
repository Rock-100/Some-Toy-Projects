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
#define offset 18750000
#define MOD 100007

typedef long long LL;

int squ(int x)
{
    return x * x * x;
}

struct dict
{
    int data;
    dict *next;
    dict ()
    {
        data = 0;
        next = NULL;
    }
};

dict *hashtable[MOD];

void init_hash()
{
    for (int i = 0; i < MOD; i++)
        hashtable[i] = NULL;
}

void insert_hash(int num)
{
    int id = num % MOD;
    if (hashtable[id] == NULL)
    {
        hashtable[id] = new dict;
        hashtable[id]->data = num;
    }
    else
    {
        dict *p = hashtable[id];
        while (p->next != NULL)
            p = p->next;
        p->next = new dict;
        p->next->data = num;
    }

}

int find_hash(int num)
{
    int id = num % MOD;
    int ans = 0;
    dict *p = hashtable[id];
    while (p != NULL)
    {
        if(p->data == num)
            ans++;
        p = p->next;
    }
    return ans;
}

void destory_hash()
{
    for (int i = 0; i < MOD; i++)
    {
        dict *p = hashtable[i];
        while (p != NULL)
        {
            dict *q = p;
            p = q->next;
            delete q;
        }
        hashtable[i] = NULL;
    }
}

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    init_hash();
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            if (i * j)
            {
                int num = -a[0] * squ(i) - a[1] * squ(j) + offset;
                insert_hash(num);
            }
    LL res = 0;
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            for (int k = -50; k <= 50; k++)
                if (i * j * k)
                {
                    int num = a[2] * squ(i) + a[3] * squ(j) + a[4] * squ(k) + offset;
                    res += find_hash(num);
                }
    cout << res << endl;

    destory_hash();

    return 0;
}
