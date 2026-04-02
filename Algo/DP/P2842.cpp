#include <iostream>
#include <vector>
// 用于取最小值
#include <algorithm>
using namespace std;

int main()
{
    int n, w; // 纸币种类n 和 目标金额w
    cin >> n >> w;

    vector<int> coins(n);
    // 输入每种纸币的面额
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    // 初始化dp数组：dp[i] = 凑出i元的最少纸币数
    // 用一个极大值(0x3f3f3f3f)表示初始无法凑出
    const int INF = 0x3f3f3f3f;
    vector<int> dp(w + 1, INF);
    dp[0] = 0; // 凑0元需要0张纸币

    // 遍历所有金额 1 ~ w
    for (int i = 1; i <= w; ++i)
    {
        // 遍历每种纸币
        for (int coin : coins)
        {
            // 当前纸币面额 ≤ 目标金额，且能凑出 i-coin 的金额
            if (coin <= i && dp[i - coin] != INF)
            {
                // 状态转移：更新最小张数
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    cout << dp[w] << endl;
    return 0;
}
