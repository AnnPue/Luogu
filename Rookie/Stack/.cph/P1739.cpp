#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int cntLeftParentheses = 0;
    cin >> s;
    for (const char &c : s)
    {
        if (c == '(')
            cntLeftParentheses++;
        else if (c == ')')
            cntLeftParentheses--;
        if (cntLeftParentheses < 0)
        {
            cout << "NO";
            return 0;
        }
    }
    if (cntLeftParentheses)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}