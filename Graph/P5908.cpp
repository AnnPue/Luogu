#include <bits/stdc++.h>
using namespace std;

vector<int> g[120005];
bool vis[120005];
int n, d;

int bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 1;
    int ans = 0;

    while (!q.empty())
    {
        auto [now, dis] = q.front();
        q.pop();

        if (dis == d)
            continue;

        for (int v : g[now])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                ans++;
                q.push({v, dis + 1});
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << bfs() << endl;
    return 0;
}
