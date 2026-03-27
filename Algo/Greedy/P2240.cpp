#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    double weigh;
    double total_value;
    double value;
} Gold;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<Gold> sgold(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sgold[i].weigh >> sgold[i].total_value;
        sgold[i].value = sgold[i].total_value / sgold[i].weigh;
    }
    sort(sgold.begin(), sgold.end(), [](Gold a, Gold b)
         { return a.total_value * b.weigh < b.total_value * a.weigh; });
    double ans = 0;
    while (sgold.back().weigh < t && !sgold.empty())
    {
        t -= sgold.back().weigh;
        ans += sgold.back().total_value;
        sgold.pop_back();
    }
    if (!sgold.empty())
    {
        ans += t * sgold.back().value;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}