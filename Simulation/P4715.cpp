#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    n = 1 << n;
    queue<pair<int, int>> q;
    for (int id = 1; id <= n; id++)
    {
        int power;
        cin >> power;
        q.push(make_pair(power, id));
    }
    while (q.size() > 2)
    {
        pair<int, int> a, b;
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        if (a.first > b.first)
            q.push(a);
        else
            q.push(b);
    }
    pair<int, int> a, b;
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    int silver = a.first > b.first ? b.second : a.second;
    cout << silver;
    return 0;
}