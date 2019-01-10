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

char C = '@';
struct HT
{
    int freq;
    char data;
    HT *left, *right;
    HT (int _f = 0, char _d = C, HT *_l = NULL, HT *_r = NULL)
    {
        freq = _f;
        data = _d;
        left = _l;
        right = _r;
    }
};
bool operator < (HT a, HT b)
{
    return a.freq > b.freq;
}

HT *huffmantree = NULL;
priority_queue<HT> pq;
map<char, string> code;

void create()
{
    while (pq.size() > 1)
    {
        HT *left = new HT;
        HT *right = new HT;
        *left = pq.top();
        pq.pop();
        *right = pq.top();
        pq.pop();
        HT temp(left->freq + right->freq, C, left, right);
        pq.push(temp);
    }
    huffmantree = new HT;
    *huffmantree = pq.top();
    pq.pop();
}

void encode(HT *root, string s = string())
{
    if (root->data != C)
    {
        code[root->data] = s;
    }
    else
    {
        encode(root->left, s + "0");
        encode(root->right, s + "1");
    }
}

void destory(HT *&root)
{
    if (root)
    {
        destory(root->left);
        destory(root->right);
        delete root;
        root = NULL;
    }
}

void print()
{
    for (map<char, string>::iterator it = code.begin(); it != code.end(); it++)
        cout << (*it).first << " " << (*it).second << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        HT temp;
        cin >> temp.data >> temp.freq;
        pq.push(temp);
    }

    create();

    encode(huffmantree);

    destory(huffmantree);

    print();

    return 0;
}

/*
5
A 1
B 2
C 3
D 6
E 12
*/
