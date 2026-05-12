#include <map> //映射要用
#include <stdio.h>
using std::map;
int t, n, k, x, a, b, i;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        map<int, int> l, r; // l表示最早一次，r表示最晚一次
                            // 不这样要clear()，反而麻烦，不如再申请一个
        scanf("%d %d", &n, &k);
        for (i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            if (!l[x])    // 没见过
                l[x] = i; // 记录
            r[x] = i;     // 不断更新
        }
        while (k--)
        {
            scanf("%d %d", &a, &b);
            if (l[a] && l[b] && l[a] <= r[b]) // 都出现过且ai最早一次比bi最晚一次早，就可以
                puts("YES");
            else
                puts("NO"); // 反之，不行
        }
    }
    return 0;
}
