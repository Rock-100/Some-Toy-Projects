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

int squ(int x)
{
    return x * x * x;
}

struct Tree
{
    int data;
    int cnt;
    Tree *left, *right;
    Tree ()
    {
        data = 0;
        cnt = 0;
        left = NULL;
        right = NULL;
    }
};

void tree_insert(Tree *&root, int val)
{
    if (root)
    {
        if (root->data > val)
            tree_insert(root->left, val);
        else if (root->data < val)
            tree_insert(root->right, val);
        else
            (root->cnt)++;
    }
    else
    {
        root = new Tree;
        root->data = val;
        root->cnt = 1;
    }
}

int tree_find(Tree *root, int val)
{
    if (root)
    {
        if (root->data > val)
            return tree_find(root->left, val);
        else if (root->data < val)
            return tree_find(root->right, val);
        else
            return root->cnt;
    }
    else
        return 0;
}

void tree_destory(Tree *&root)
{
    if (root)
    {
        tree_destory(root->left);
        tree_destory(root->right);
        delete root;
        root = NULL;
    }
}

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    Tree *root = NULL;
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            if (i * j)
            {
                int num = -a[0] * squ(i) - a[1] * squ(j);
                tree_insert(root, num);
            }
    LL res = 0;
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            for (int k = -50; k <= 50; k++)
                if (i * j * k)
                {
                    int num = a[2] * squ(i) + a[3] * squ(j) + a[4] * squ(k);
                    res += tree_find(root, num);
                }
    cout << res << endl;
    tree_destory(root);
    return 0;
}
