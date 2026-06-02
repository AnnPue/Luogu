#include <cstdio>
#define int long long
signed main()
{
    int a, b, mod;
    scanf("%lld%lld%lld", &a, &b, &mod);
    int ans = 1;
    int base = a % mod;
    int power = b;
    while (power > 0)
    {
        if (power & 1)
        {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        power >>= 1;
    }
    printf("%d^%d mod %d=%d", a, b, mod, ans);
}
