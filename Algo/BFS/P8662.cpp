#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];                                     // 地图
int visited[N][N] = {0};                           // 标记是否搜索过
int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4种移动方式
int flag;                                          // 标记这个岛是否被淹没

void bfs(int x, int y)
{
    queue<pair<int, int>> q; // 待访问的陆地名单
    q.push({x, y});          // 将起点(x, y)加入
    visited[x][y] = 1;       // 标记已访问

    while (q.size()) // 只要队列不为空，就一直处理
    {
        pair<int, int> t = q.front();    // 取出队首的陆地
        q.pop();                         // 取出后删掉
        int tx = t.first, ty = t.second; // 处理这块陆地
        // 判断flag=0加快速度
        if (flag == 0 && mp[tx][ty + 1] == '#' && mp[tx][ty - 1] == '#' && mp[tx + 1][ty] == '#' && mp[tx - 1][ty] == '#')
            flag = 1;               // 上下左右都是#，是高地
        for (int i = 0; i < 4; i++) // 搜索上下左右陆地
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