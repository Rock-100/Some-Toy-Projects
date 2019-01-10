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



int main()
{
    stack<int> st;

    st.push(3);
    st.push(7);
    st.push(4);

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    return 0;
}
