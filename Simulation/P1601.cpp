// 高精度加法
#include <iostream>
using namespace std;
string BigUIntadd(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    // 将较短的字符串前面补0，使两字符串长度相等
    int diffLen = len1 - len2;
    if (diffLen < 0)
    {
        for (int i = 0; diffLen < i; --i)
        {
            s1 = "0" + s1;
        }
    }
    else
    {
        for (int i = 0; i < diffLen; ++i)
        {
            s2 = "0" + s2;
        }
    }
    len1 = s1.size();
    int carry = 0, tdig; // carry：进位，tdig：现在处理位
    string ans;          // 答案串
    for (int i = len1 - 1; i >= 0; --i)
    { // 从低位开始处理
        tdig = s1[i] - '0' + s2[i] - '0' + carry;
        carry = tdig / 10; // 进位只能是0或1
        tdig %= 10;
        ans = char(tdig + '0') + ans;
    }
    if (carry) // 如果进位不是0，则是1
        ans = "1" + ans;
    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << BigUIntadd(s1, s2);
    return 0;
}
