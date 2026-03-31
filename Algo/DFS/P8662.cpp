#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];                                     // 地图
int visited[N][N] = {0};                           // 标记是否搜索过
int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4种移动方式
int flag;                                          // 标记这个岛是否被淹没

void dfs(int x, int y)
{
    visited[x][y] = 1; // 标记这个#被搜索过
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' && mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = 1; // 上下左右都是#，则此处为高地，置1
    for (int i = 0; i < 4; i++)
    {
        // 向四周移动
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        // visited=0剪枝，避免重复进行dfs
        if (visited[nx][ny] == 0 && mp[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> mp[i]; // 每次获得一行
    int ans = 0;

    // 搜索所有位置
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == 0 && mp[i][j] == '#') // 发现新岛
            {
                flag = 0;      // 假设被淹没
                dfs(i, j);     // 找高地，若有，flag置1
                if (flag == 0) // 这个岛被淹没
                    ans++;     // 计数
            }
        }

    cout << ans;
    return 0;
}