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

#define N 100100
int n;

#define X first
#define Y second
typedef pair<double, double> Point;
Point point[N];

#define INF 1e30

bool cmp_x(Point a, Point b)
{
    return a.X < b.X;
}

bool cmp_y(Point a, Point b)
{
    return a.Y < b.Y;
}

double dis(Point a, Point b)
{
    double x = a.X - b.X;
    double y = a.Y - b.Y;
    return sqrt(x * x + y * y);
}

double ClosestPair(Point *point, Point *pointend)
{
    int n = pointend - point;
    if (n == 1)
        return INF;
    else if (n == 2)
        return dis(point[0], point[1]);
    else
    {
        int mid = n >> 1;
        double d = min(ClosestPair(point, point + mid), ClosestPair(point + mid, pointend));
        Point *p = new Point[n];
        int num = 0;
        for (int i = 0; i < n; i++)
            if (fabs(point[i].X - point[mid].X) < d - eps)
                p[num++] = point[i];
        sort(p, p + num, cmp_y);
        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (p[j].Y - p[i].Y > d - eps)
                    break;
                d = min(d, dis(p[i], p[j]));
            }
        }
        delete [] p;
        return d;
    }
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &point[i].X, &point[i].Y);

        sort(point, point + n, cmp_x);

        printf("%.2f\n", ClosestPair(point, point + n) / 2);
    }

    return 0;
}
