#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; // 硬币种数
    int w; // 需要支付的金额
    cin >> n >> w;
    vector<int> cash(n + 1, 0), f(w + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> cash[i];
    }
    f[0] = 1;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = i - cash[j];
            if (0 <= x)
            {
                f[i] = (f[i] + f[x]) % MOD; // 凑出 i 元的组方式是 i 分别减去每种纸币面额的方式数的和
            }
        }
    }
    cout << f[w] % MOD << endl;
}