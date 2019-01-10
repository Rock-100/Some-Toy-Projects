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

struct Tree
{
    int data;
    Tree *left, *right;
    Tree (int _d = 0, Tree *_l = NULL, Tree *_r = NULL)
    {
        data = _d;
        left = _l;
        right = _r;
    }
};

void tree_insert(Tree *&root, int val)
{
    if (root)
    {
        if (root->data > val)
            tree_insert(root->left, val);
        if (root->data < val)
            tree_insert(root->right, val);
    }
    else
    {
        root = new Tree;
        root->data = val;
    }
}

bool tree_find(Tree *root, int val)
{
    if (root)
    {
        if (root->data > val)
            return tree_find(root->left, val);
        else if (root->data < val)
            return tree_find(root->right, val);
        else
            return true;
    }
    else
        return false;
}

void tree_visit(Tree *root)
{
    if (root)
    {
        tree_visit(root->left);
        cout << root->data << " ";
        tree_visit(root->right);
    }
    else
        return;
}

void tree_erase(Tree *&root, int val)
{
    if (root)
    {
        if (root->data < val)
            tree_erase(root->right, val);
        else if (root->data > val)
            tree_erase(root->left, val);
        else
        {
            if (root->left == NULL)
            {
                Tree *temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == NULL)
            {
                Tree *temp = root->left;
                delete root;
                root = temp;
            }
            else
            {
                Tree *p = root->left;
                while (p->right->right)
                    p = p->right;
                Tree *q = p->right;
                p->right = q->left;
                q->left = root->left;
                q->right = root->right;
                delete root;
                root = q;
            }
        }
    }
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
    int num[20] = {11, 23, 2, 14, 77, 0, 9, 2, 3, 14};
    int n = 10;

    Tree *root = NULL;
    for (int i = 0; i < n; i++)
        tree_insert(root, num[i]);

    tree_visit(root);
    cout << endl;

    cout << tree_find(root, 9) << endl;
    cout << tree_find(root, -1) << endl;

    tree_erase(root, 3);
    tree_erase(root, 11);
    tree_erase(root, -1);

    tree_visit(root);
    cout << endl;

    tree_destory(root);

    return 0;
}
