#include <iostream>
#include <cstring>
using namespace std;

// 全局变量：最多4组，每组最多20个物品，背包容量最大1200
int groupSizes[5];
int items[21];
int dp[1210];
int totalResult = 0;

int main()
{
    // 1. 读取4组数据的物品数量
    for (int i = 1; i <= 4; i++)
    {
        cin >> groupSizes[i];
    }

    // 2. 依次处理每一组物品
    for (int groupIdx = 1; groupIdx <= 4; groupIdx++)
    {
        int groupSum = 0;
        // 读取当前组的物品数值，并计算总和
        for (int i = 1; i <= groupSizes[groupIdx]; i++)
        {
            cin >> items[i];
            groupSum += items[i];
        }

        // 3. 动态规划 (01背包思想) 求解
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // 初始化：和为0的状态是可达的

        // 遍历当前组的每个物品
        for (int i = 1; i <= groupSizes[groupIdx]; i++)
        {
            // 逆序遍历背包容量，防止物品被重复使用
            for (int j = groupSum; j >= 0; j--)
            {
                if (dp[j])
                {                         // 如果当前和 j 可以被凑出
                    dp[j + items[i]] = 1; // 那么 j + 当前物品值 也可以被凑出
                }
            }
        }

        // 4. 寻找最优解：使两堆差值最小，并记录较大堆的值
        int minDiff = groupSum; // 初始化为最大可能的差值
        int maxPart = groupSum;

        for (int i = 0; i <= groupSum; i++)
        {
            if (dp[i])
            {                                              // 遍历所有能凑出的和 i
                int currentDiff = abs(i - (groupSum - i)); // 计算两堆的差值
                if (currentDiff < minDiff)
                {
                    minDiff = currentDiff;
                    maxPart = max(i, groupSum - i); // 取两堆中较大的那个
                }
            }
        }

        totalResult += maxPart; // 累加到最终结果
    }

    cout << totalResult << endl;
    return 0;
}