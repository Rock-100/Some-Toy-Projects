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

struct BiTree
{
    char data;
    BiTree *lchild, *rchild;
};

void Create(BiTree *&bt)
{
    char c;
    cin >> c;
    if (c == '@')
        bt = NULL;
    else
    {
        bt = new BiTree;
        bt->data = c;
        Create(bt->lchild);
        Create(bt->rchild);
    }
}

void PreOrderVisit(BiTree *bt, int dep = 0)
{
    if (bt)
    {
        cout << bt->data << "(" << dep << ")";
        PreOrderVisit(bt->lchild, dep + 1);
        PreOrderVisit(bt->rchild, dep + 1);
    }
    else
        cout << "@";

    if (dep == 0)
        cout << endl;
}

void InOrderVisit(BiTree *bt, int dep = 0)
{
    if (bt)
    {
        InOrderVisit(bt->lchild, dep + 1);
        cout << bt->data << "(" << dep << ")";
        InOrderVisit(bt->rchild, dep + 1);
    }
    else
        cout << "@";

    if (dep == 0)
        cout << endl;
}

void PosOrderVisit(BiTree *bt, int dep = 0)
{
    if (bt)
    {
        PosOrderVisit(bt->lchild, dep + 1);
        PosOrderVisit(bt->rchild, dep + 1);
        cout << bt->data << "(" << dep << ")";
    }
    else
        cout << "@";

    if (dep == 0)
        cout << endl;
}

queue<BiTree *> que;
void bfs(BiTree *bt)
{
    if (bt == NULL)
        return;
    cout << bt->data << " ";
    que.push(bt);

    while (que.size())
    {
        BiTree *b = que.front();
        que.pop();

        if (b->lchild)
        {
            cout << b->lchild->data << " ";
            que.push(b->lchild);
        }

        if (b->rchild)
        {
            cout << b->rchild->data << " ";
            que.push(b->rchild);
        }
    }
    cout << endl;
}

void dfs(BiTree *bt)
{
    if (bt == NULL)
        return;
    cout << bt->data << " ";

    dfs(bt->lchild);
    dfs(bt->rchild);
}

void Destory(BiTree *&bt)
{
    if (bt)
    {
        Destory(bt->lchild);
        Destory(bt->rchild);
        delete bt;
        bt = NULL;
    }

}

int main()
{
    BiTree *bt = NULL;

    Create(bt);

    PreOrderVisit(bt);

    InOrderVisit(bt);

    PosOrderVisit(bt);

    bfs(bt);

    dfs(bt);

    Destory(bt);

    return 0;
}

/*
ABC@@D@@E@F@@

        A
   B        E
C     D         F
*/
