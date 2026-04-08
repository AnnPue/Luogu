#include <iostream>
using namespace std;

const int N = 105;
int n, m;
int res = 0;
char mp[N][N];
bool visited[N][N] = {0};
int lnk[8][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + lnk[i][0], ny = y + lnk[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && mp[nx][ny] == 'W')
        {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> (mp[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'W' && !visited[i][j])
            {
                visited[i][j] = 1;
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}