// Train and Queries
// 用queue会超时
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            int station;
            cin >> station;
            q.push(station);
        }
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            queue<int> q1 = q;
            bool able = false;
            while (!q1.empty())
            {
                int sta = q1.front();
                q1.pop();
                if (sta == a)
                    break;
            }
            while (!q1.empty())
            {
                int sta = q1.front();
                q1.pop();
                if (sta == b)
                {
                    able = true;
                    break;
                }
            }
            cout << (able ? "YES" : "NO") << endl;
        }
    }
}