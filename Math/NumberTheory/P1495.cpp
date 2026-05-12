// 【模板】中国剩余定理（CRT）/ 曹冲养猪
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
int n, a[N], b[N];

pair<int, int> exgcd(int a, int b)
{
    if (b == 0)
        return {1, 0};
    auto [x, y] = exgcd(b, a % b);
    return {y, x - a / b * y};
}

int inv(int a, int p)
{
    auto [x, y] = exgcd(a, p);
    return (x + p) % p; // exgcd 求出的解有可能是负的，所以取模一下转成正的
}

int CRT(int n, int *a, int *b)
{
    int M = 1, x = 0;
    for (int i = 1; i <= n; i++)
        M *= a[i];
    for (int i = 1; i <= n; i++)
    {
        __int128 Mi = M / a[i], Ti = inv(Mi, a[i]);
        x = (x + Mi * Ti * b[i] % M) % M;
    }
    return x;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    cout << CRT(n, a, b);
    return 0;
}
