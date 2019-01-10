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

#define N 270000
complex<double> FA[N], FB[N];
void convolution(LL *a, int m1, LL *b, int m2, LL *c)
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

int n;
int branch[N];
LL num[N];

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &branch[i]);
        sort(branch, branch + n);
        int maxlen = branch[n - 1];
        memset(num, 0 ,sizeof(num));
        for (int i = 0; i < n; i++)
            num[branch[i]]++;
        convolution(num, maxlen + 1, num, maxlen + 1, num);
        int m = 2 * maxlen + 1;
        for (int i = 0; i < n; i++)
            num[2 * branch[i]]--;
        for (int i = 0; i < m; i++)
            num[i] /= 2;

        for (int i = 1; i < m; i++)
            num[i] += num[i - 1];

        LL res = 0;
        for (int i = 2; i < n; i++)
        {
            res += num[m - 1] - num[branch[i]];
            res -= n - 1;
            res -= LL(n - 1 - i) * (n - 2 - i) / 2;
            res -= LL(n - 1 - i) * i;
        }
        LL all = (LL)n * (n - 1) * (n - 2) / 6;
        printf("%.7f\n", (double)res / all);

    }
    return 0;
}
