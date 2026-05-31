#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

struct Edge
{
    ll to, step;
    bool operator<(const Edge &s) const
    {
        return s.step < step;
    }
};

const ll MAXN = 1e5 + 5;
const ll INF = 0x7fffffff;

bool vis[MAXN];
vector<Edge> G[MAXN];
ll n, m, s, dist[MAXN];

void add_edge(ll u, ll v, ll w)
{
    G[u].push_back({v, w});
    return;
}

void dijkstra()
{
    priority_queue<Edge> q;
    q.push({s, 0});
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
    while (!q.empty())
    {
        Edge temp = q.top();
        q.pop();
        int u = temp.to;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i].to;
            if (!vis[v])
            {
                dist[v] = min(dist[v], G[u][i].step + temp.step);
                q.push({v, dist[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
    {
        cout << dist[i] << ' ';
    }
    return 0;
}
