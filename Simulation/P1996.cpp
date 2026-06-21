/* 约瑟夫问题 */
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        cnt = (cnt + 1) % k;
        int now = q.front();
        q.pop();
        if (!cnt)
            cout << now << " ";
        else
            q.push(now);
    }
}