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


void change_address(complex<double> *f, int n)
{
    int m = n - 1, bit = 0;
    while (m)
    {
        bit++;
        m >>= 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int addr = 0;
        for (int j = 0; j < bit; j++)
        {
            if (i & (1 << j))
                addr += 1 << (bit - j - 1);
        }
        if (i < addr)
            swap(f[i], f[addr]);
    }
}

void fft(complex<double> *f, int n)
{
    change_address(f, n);

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
}

void Ifft(complex<double> *f, int n)
{
    for (int i = 0; i < n; i++)
        f[i] = conj(f[i]);
    fft(f, n);
    for (int i = 0; i < n; i++)
    {
        f[i] = conj(f[i]);
        f[i] /= n;
    }
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

#define N 150000
complex<double> FA[N], FB[N];
void convolution(int *a, int m1, int *b, int m2, int *c)
{
    int n = m1 + m2 -1;
    complement(n);
    for (int i = 0; i < n; i++)
        FA[i] = complex<double>(a[i], 0);
    for (int i = 0; i < n; i++)
        FB[i] = complex<double>(b[i], 0);
    fft(FA, n);
    fft(FB, n);
    for (int i = 0; i < n; i++)
        FA[i] = FA[i] * FB[i];
    Ifft(FA, n);
    for (int i = 0; i < n; i++)
        c[i] = FA[i].real() + 0.5;
}

int A[N], B[N], res[N];


char in1[N], in2[N];
int main()
{
    while (scanf("%s%s", in1, in2) != EOF)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(res, 0, sizeof(res));
        int n1 = strlen(in1);
        for (int i = 0; i < n1; i++)
            A[i] = in1[n1 - i - 1] - '0';

        int n2 = strlen(in2);
        for (int i = 0; i < n2; i++)
            B[i] = in2[n2 - i - 1] - '0';

        convolution(A, n1, B, n2, res);
        int n = n1 + n2 - 1;
        for (int i = 0; i < n; i++)
            if (res[i] > 9)
            {
                res[i + 1] += res[i] /10;
                res[i] = res[i] % 10;
            }
        if (res[n])
            n++;
        while (n > 1 && !res[n - 1])
            n--;
        for (int i = 0; i < n; i++)
            in1[i] = res[n - i - 1] + '0';
        in1[n] = '\0';
        printf("%s\n", in1);
    }
    return 0;
}
