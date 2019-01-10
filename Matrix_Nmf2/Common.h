#ifndef __COMMON__
#define __COMMON__

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

inline bool isZero(double f)
{
	return abs(f) < eps;
}

inline double douRand()
{
	static bool ini = 0;
	if (ini == 0)
	{
		ini = 1;
		srand((unsigned)time(NULL));
	}
	return rand() / double(RAND_MAX);
}

#endif 