#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> x; // 小根堆
priority_queue<int> d; // 大根堆
int p, k, m, a, z[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    cin >> a;
    x.push(-1 * a);               // 将第一个数放入小根堆
    cout << -1 * x.top() << endl; // 输出
    for (int i = 2; i <= m; i++)
    {
        cin >> a;
        if (i & 1) // 如果i为奇数
        {
            int c = d.top();
            if (a >= c)         // Ai比大根堆的堆顶大
                x.push(-1 * a); // 直接插入小根堆
            else                // Ai比大根堆的堆顶小
            {
                d.pop();
                d.push(a);
                x.push(-1 * c); // 大根堆的堆顶放入小根堆，Ai放入大根堆
            }
            cout << -1 * x.top() << '\n'; // i为奇数时输出中位数
        }
        else // 如果i为偶数
        {
            int c = x.top();
            if (a <= -1 * c) // Ai比小根堆堆顶小
                d.push(a);   // 直接插入大根堆
            else             // Ai比小根堆堆顶大
            {
                x.pop();
                x.push(-1 * a);
                d.push(-1 * c); // 小根堆堆顶放入大根堆，Ai放入小根堆
            }
        }
    }
    return 0; // 结束
}