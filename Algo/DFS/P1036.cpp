#include <bits/stdc++.h>
using namespace std;

vector<int> nums(23); // 1≤n≤20
int ans = 0, k, n;

inline bool isprime(int x) // 判断一个数是否是素数
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int now, int sum, int idx)
{
    if (now == k)
    {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int i = idx; i <= n - k + now + 1; i++) // 不降原则
    {
        dfs(now + 1, sum + nums[i], i + 1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}