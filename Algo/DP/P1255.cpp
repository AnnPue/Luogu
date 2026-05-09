#include <bits/stdc++.h>
using namespace std;
int a[5005], b[5005], c[5005]; // 开大一点
string f[5005];
void zh(string s, int a[], int &n)
{
    n = s.size();
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i)
    {
        a[i + 1] = s[i] - 48;
    }
}
void bigIntAdd(string sa, string sb, int k)
{ // 高精度加法
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    int la, lb, lc;
    zh(sa, a, la);
    zh(sb, b, lb);
    lc = max(la, lb);
    for (int i = 1; i <= lc; ++i)
    {
        c[i] = a[i] + b[i];
    }
    int jw = 0;
    for (int i = 1; i <= lc; ++i)
    {
        c[i] = c[i] + jw;
        jw = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if (jw)
    {
        lc++;
        c[lc] = jw;
    }
    for (int i = lc; i >= 1; i--)
    {
        f[k] += char(c[i] + 48);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    f[1] = "1";
    f[2] = "2"; // f[2]要等于2
    for (int i = 3; i <= n; ++i)
    { // 每个数都要做f[i-1]+f[i-2]的高精度
        bigIntAdd(f[i - 1], f[i - 2], i);
    }
    cout << f[n];
    return 0;
}
