#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<char, char> m = {
    {'(', ')'}, {'[', ']'}, {'{', '}'}};
bool isValid(const string &s)
{
    string st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push_back(c);
        else
        {
            if (st.empty())
                return false;
            char top = st.back();
            if (c != m[top])
                return false;
            st.pop_back(); // 匹配成功，出栈
        }
    }
    return st.empty();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (isValid(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}