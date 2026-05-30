#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int bx, by, mx, my;
    cin >> bx >> by >> mx >> my;
    vector<vector<bool>> block(bx + 1, vector<bool>(by + 1, false));
    int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
    for (int i = 0; i < 9; ++i)
    {
        int nx = mx + dx[i];
        int ny = my + dy[i];
        if (nx >= 0 && nx <= bx && ny >= 0 && ny <= by)
        {
            block[nx][ny] = true;
        }
    }

    if (block[0][0])
    {
        cout << 0;
        return 0;
    }

    vector<vector<ll>> dp(bx + 1, vector<ll>(by + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= bx; ++i)
    {
        for (int j = 0; j <= by; ++j)
        {
            if (block[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
                continue;
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[bx][by];
}