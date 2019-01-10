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

#define INF 1e30
#define N 200100
struct Point
{
    double x, y;
    bool type;
    Point (double _x = 0, double _y = 0, bool _type = 0):x(_x), y(_y), type(_type)
    {
    }
};
int n;
Point point[N];

bool cmp_x(Point a, Point b)
{
    return a.x < b.x;
}

bool cmp_y(Point a, Point b)
{
    return a.x > b.x;
}

double dis(Point a, Point b)
{
    if (a.type == b.type)
        return INF;
    else
    {
        double x = a.x - b.x;
        double y = a.y - b.y;
        return sqrt(x * x + y * y);
    }
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
        double d = min(ClosestPair(point, point + mid), ClosestPair(point + mid + 1, pointend));
        Point *p = new Point[n];
        int num = 0;
        for (int i = 0; i < n; i++)
            if (fabs(point[i].x - point[mid].x) < d - eps)
                p[num++] = point[i];

        sort(p, p + num, cmp_y);
        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (p[j].y - p[i].y > d - eps)
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
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].type = 0;
        }
        for (int i = n; i < 2 * n; i++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].type = 1;
        }
        sort(point, point + 2 * n, cmp_x);
        printf("%.3f\n", ClosestPair(point, point + 2 * n));
    }

    return 0;
}
