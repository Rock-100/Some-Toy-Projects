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

#define N 30
typedef map<char, int> IDtable;
typedef map<int, char> Nametable;
IDtable m_ID, w_ID;
Nametable w_name;

int n;
struct MAN
{
    int pre[N];
    int choice;
    int match;
};
MAN m[N];

struct WOMAN
{
    int rate[N];
    int match;
};
WOMAN w[N];

void init()
{
    m_ID.clear();
    w_ID.clear();
    w_name.clear();
    for (int i = 0; i < N; i++)
    {
        m[i].match = w[i].match = -1;
        m[i].choice = 0;
    }
}

void stable_marriage()
{
    set<int> freeman;
    for (int i = 0; i < n; i++)
        freeman.insert(i);

    while (!freeman.empty())
    {
        int man = *freeman.begin();
        int woman = m[man].pre[m[man].choice];
        m[man].choice++;

        if (w[woman].match == -1)
        {
            w[woman].match = man;
            m[man].match = woman;
            freeman.erase(man);
        }
        else if (w[woman].rate[man] > w[woman].rate[w[woman].match])
        {
            int third = w[woman].match;
            w[woman].match = man;
            m[man].match = woman;
            m[third].match = -1;
            freeman.erase(man);
            freeman.insert(third);
        }

    }
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        init();
        cin >> n;
        string in;
        for (int i = 0; i < n; i++)
        {
            cin >> in;
            m_ID.insert(make_pair(in[0], i));
        }

        for (int i = 0; i < n; i++)
        {
            cin >> in;
            w_ID.insert(make_pair(in[0], i));
            w_name.insert(make_pair(i, in[0]));
        }

        for (int i = 0; i < n; i++)
        {
            cin >> in;
            for (int j = 2; j < in.size(); j++)
                m[m_ID[in[0]]].pre[j - 2] = w_ID[in[j]];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> in;
            for (int j = 2; j < in.size(); j++)
                w[w_ID[in[0]]].rate[m_ID[in[j]]] = n + 1 - j;
        }

        stable_marriage();

        for (IDtable::iterator it = m_ID.begin(); it != m_ID.end(); it++)
        {
            pair<char, int> p = *it;
            cout << p.first << " " << w_name[m[p.second].match] << endl;
        }

        if (cas)
            cout << endl;
    }

    return 0;
}

