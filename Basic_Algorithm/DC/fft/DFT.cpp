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
#include <complex>

using namespace std;

#define eps 1e-10
#define pi acos(-1)

typedef long long LL;

#define N 100000

complex<double> x[N];
complex<double> f[N];

void dft(complex<double> *x, complex<double> *f, int n)
{
    double theta = -2 * pi / n;
    complex<double> w(cos(theta), sin(theta));
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
        for (int j = 0; j < n; j++)
        {
            f[i] += x[j] * pow(w, i * j);
        }
    }
}

void Idft(complex<double> *x, complex<double> *f, int n)
{
    double theta = 2 * pi / n;
    complex<double> w(cos(theta), sin(theta));
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
        for (int j = 0; j < n; j++)
        {
            x[i] += f[j] * pow(w, i * j);
        }
        x[i] /= n;
    }
}

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
        x[i] = complex<double>(i + 1, 0);
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    dft(x, f, n);
    for (int i = 0; i < n; i++)
        cout << f[i] << " ";
    cout << endl;

    Idft(x, f, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";

    return 0;
}
