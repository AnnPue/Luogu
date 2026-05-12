#include <iostream>
const int N = 11;
const int MOD = 2004;
typedef long long ll;

int n, l, r;
ll swt[N], fact = 1, sum;

inline ll C(int a, int b)
{
    ll m = MOD * fact;
    ll ans = 1;
    for (int i = b + 1 - a; i <= b; i++)
        ans = ans * i % m;
    return (ans / fact) % MOD;
}

void dfs(int val, int step, int k, int lmt)
{
    if (k > lmt)
        return;
    if (step == n + 1)
    {
        sum += 1ll * val * C(n, n + lmt - k) % MOD;
        sum %= MOD;
        return;
    }
    dfs(val, step + 1, k, lmt);
    dfs(-val, step + 1, k + swt[step] + 1, lmt);
}

inline ll calcu(int x)
{
    sum = 0;
    dfs(1, 1, 0, x);
    return (sum % MOD + MOD) % MOD;
}

int main()
{
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", swt + i);
        fact *= i;
    }
    printf("%lld\n", ((calcu(r) - calcu(l - 1)) % MOD + MOD) % MOD);
    return 0;
}