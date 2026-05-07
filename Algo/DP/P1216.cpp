#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> tri(n + 1, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    int max1 = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
            if (i == n)
                max1 = max(max1, tri[i][j]);
        }
    }
    cout << max1;
    return 0;
}