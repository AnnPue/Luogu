#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    unordered_map<char, char> m = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}};
    while (t--)
    {
        string s;
        cin >> s;
        bool isValid = true;
        stack<char> st;
        for (const char &c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.empty())
                {
                    isValid = false;
                    break;
                }
                char now = st.top();
                if (c != m[now])
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            isValid = false;

        if (isValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}