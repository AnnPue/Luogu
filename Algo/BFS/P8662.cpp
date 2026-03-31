#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];                                     // 地图
int visited[N][N] = {0};                           // 标记是否搜索过
int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4种移动方式
int flag;                                          // 标记这个岛是否被淹没

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while (q.size())
    {
        pair<int, int> t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        if (flag == 0 && mp[tx][ty + 1] == '#' && mp[tx][ty - 1] == '#' && mp[tx + 1][ty] == '#' && mp[tx - 1][ty] == '#')
            flag = 1; // 上下左右都是#，是高地
        for (int i = 0; i < 4; i++)
        {
            int nx = tx + mv[i][0];
            int ny = ty + mv[i][1];
            // 将陆地入队列
            if (visited[nx][ny] == 0 && mp[nx][ny] == '#')
            {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
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
                bfs(i, j);     // 找高地，若有，flag置1
                if (flag == 0) // 这个岛被淹没
                    ans++;     // 计数
            }
        }

    cout << ans;
    return 0;
}