#include <iostream>
using namespace std;
string s;
void solve(int demand)
{
    int a = 0, b = 0; // 双方分数
    for (auto si : s)
    {
        if (si == 'W')
            ++a;
        else
            ++b;
        // 领先者分数达到要求，且分差大于或者等于2，才一局结束
        if (max(a, b) >= demand && abs(a - b) >= 2)
        {
            cout << a << ':' << b << endl;
            a = 0, b = 0;
        }
    }
    cout << a << ':' << b << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char c;
    while (cin >> c)
    {
        if (c == 'E')
            break;
        s += c;
    }
    solve(11);
    cout << endl;
    solve(21);
}