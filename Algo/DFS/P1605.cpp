#include <iostream>
using namespace std;
const short N = 7;

short n, m, t, sx, sy, fx, fy, res = 0;
char mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char visited[N][N] = {0};
char board[N][N] = {0};

void dfs(short x, short y)
{
    if (x == fx && y == fy)
    {
        res++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && !board[nx][ny])
        {
            visited[nx][ny] = 1;
            dfs(nx, ny);
            visited[nx][ny] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (short i = 0; i < t; i++)
    {
        int tx, ty;
        cin >> tx >> ty;
        board[tx][ty] = 1;
    }
    visited[sx][sy] = 1;
    dfs(sx, sy);
    cout << res;
    return 0;
}