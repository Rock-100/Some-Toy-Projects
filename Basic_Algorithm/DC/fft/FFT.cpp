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

void complement(complex<double> *x, int &n)
{
    if (n & (n - 1))
    {
        int m = 1;
        while (m < n)
            m <<= 1;
        for (int i = n; i < m; i++)
            x[i] = 0;
        n = m;
    }
}

void change_address(complex<double> *x, complex<double> *f, int n)
{
    int m = n - 1, bit = 0;
    while (m)
    {
        bit++;
        m >>= 1;
    }
    f[0] = x[0], f[n - 1] = x[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        int addr = 0;
        for (int j = 0; j < bit; j++)
        {
            if (i & (1 << j))
                addr += 1 << (bit - j - 1);
        }
        f[addr] = x[i];
    }
}

void fft(complex<double> *x, complex<double> *f, int n)
{
    complex<double> *xx = new complex<double>[n];
    for (int i = 0; i < n; i++)
        xx[i] = x[i];
    change_address(xx, f, n);

    for (int s = 2, ds = 1; s <= n; ds = s, s <<= 1)
    {
        double theta = -2 * pi / s;
        complex<double> ws = complex<double>(cos(theta), sin(theta));
        complex<double> w = complex<double>(1, 0);
        for (int k = 0; k < ds; k++, w *= ws)
            for (int i = k; i < n; i += s)
            {
                complex<double> temp = w * f[i + ds];
                f[i + ds] = f[i] - temp;
                f[i] = f[i] + temp;
            }
    }
    delete [] xx;
}

void Ifft(complex<double> *x, complex<double> *f, int n)
{
    complex<double> *ff = new complex<double>[n];
    for (int i = 0; i < n; i++)
        ff[i] = conj(f[i]);
    fft(ff, x, n);
    for (int i = 0; i < n; i++)
    {
        x[i] = conj(x[i]);
        x[i] /= n;
    }
    delete [] ff;
}
void complement(int &n)
{
    if (n & (n - 1))
    {
        int m = 1;
        while (m < n)
            m <<= 1;
        n = m;
    }
}
void convolution(int *a, int m1, int *b, int m2, int *c)
{
    int n = m1 + m2 -1;
    complement(n);
    complex<double> *x = new complex<double>[n];
    complex<double> *y = new complex<double>[n];

    for (int i = 0; i < n; i++)
        x[i] = complex<double>(a[i], 0);
    for (int i = 0; i < n; i++)
        y[i] = complex<double>(b[i], 0);
    fft(x, x, n);
    fft(y, y, n);
    for (int i = 0; i < n; i++)
        x[i] = x[i] * y[i];
    Ifft(x, x, n);
    for (int i = 0; i < n; i++)
        c[i] = x[i].real() + 0.5;

    delete [] x;
    delete [] y;
}
int main()
{
    int n = 3;
    for (int i = 0; i < n; i++)
        x[i] = complex<double>(i + 1, 0);
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
    complement(x, n);
    fft(x, f, n);
    Ifft(x, f, n);
    for (int i = 0; i < n; i++)
        cout << f[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    int a[20] = {1, 3, 2}, b[20] = {3, 2}, c[20];
    convolution(a, 3, b, 2, c);
    for (int i = 0; i < 5 - 1; i++)
        cout << c[i] << " ";
    return 0;
}
