#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> tri(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> tri[i][j];
            tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
        }
    }
    ll ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, tri[n][i]);
    }
    cout << ans;
}