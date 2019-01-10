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

class cycleQueue
{
public:
    cycleQueue()
    {
        head = tail = 0;
        MAX = 10;
        fill(data, data + MAX, 0);
    }
    int get_size()
    {
        return (tail -head + MAX) % MAX;
    }
    int top()
    {
        return data[head];
    }
    bool push(int num)
    {
        if (this->get_size() == (MAX - 1))
            return 0;
        data[tail] = num;
        tail = (tail + 1) % MAX;
        return 1;
    }
    bool pop()
    {
        if (head == tail)
            return 0;
        head = (head + 1) % MAX;
        return 1;
    }

private:
    int head, tail;
    int MAX;
    int data[10];
};

int main()
{
    cycleQueue cq;
    for (int i = 1; i < 20; i++)
        cq.push(2 * i - 1);
    cq.pop();
    cq.push(0);
    while (cq.get_size())
    {
        cout << cq.top() << " ";
        cq.pop();
    }
    cout << endl;

    return 0;
}
