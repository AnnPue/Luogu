#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define int long long
using namespace std;

struct Edge
{
    int to, step;

    bool operator<(const Edge &s) const
    {
        return s.step < step; // 优先队列默认是大根堆，这里要反过来
    }
};

const int maxn = 1e5 + 5;
const int INF = INT_MAX;

bool vis[maxn];         // 访问标记
vector<Edge> G[maxn];   // 邻接表存图
int n, m, s, dis[maxn]; // n:节点数 m:边数 s:起点 dis[]:距离数组

void add_edge(int u, int v, int w)
{
    G[u].push_back({v, w});
    return;
}

void Dijkstra()
{
    priority_queue<Edge> q;
    q.push({s, 0}); // 将起点加入优先队列，距离为0
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF; // 初始化距离数组为无穷大
    }
    dis[s] = 0;
    while (q.size() > 0)
    {
        Edge tmp = q.top();
        q.pop();
        int u = tmp.to;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i].to;
            if (vis[v] == 0)
            {
                dis[v] = min(dis[v], G[u][i].step + tmp.step);
                q.push({v, dis[v]});
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    Dijkstra();
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}
