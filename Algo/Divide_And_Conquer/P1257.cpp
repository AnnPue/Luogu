#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 10005;
const long double INF = 1e20L;
struct P
{
    long double x, y;
} p[N], t[N];
int n;
bool cmpx(const P &a, const P &b)
{
    return a.x < b.x;
}
bool cmpy(const P &a, const P &b)
{
    return a.y < b.y;
}
long double d(const P &a, const P &b)
{ // 计算两点之间的距离的平方
    long double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
long double f(int l, int r)
{ // 递归求解区间 [l, r] 内的最短距离的平方
    if (l == r)
        return INF;
    if (l + 1 == r)
        return d(p[l], p[r]);
    int m = (l + r) / 2;
    long double mx = p[m].x;
    long double ans = min(f(l, m), f(m + 1, r));
    int k = 0;
    for (int i = l; i <= r; i++)
    {
        if (fabsl(p[i].x - mx) < ans)
            t[k++] = p[i];
    }
    sort(t, t + k, cmpy);
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k && t[j].y - t[i].y < ans; j++)
        {
            ans = min(ans, d(t[i], t[j]));
        }
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        p[i].x = x;
        p[i].y = y;
    }
    sort(p, p + n, cmpx);
    printf("%.4Lf\n", sqrtl(f(0, n - 1)));
    return 0;
}
