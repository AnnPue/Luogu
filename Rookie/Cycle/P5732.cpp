#include <iostream>
using namespace std;
int n, a[21][21];
int main()
{
    cin >> n;
    a[1][1] = 1; // 初始化
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << a[i][j] << " "; // 输出
        cout << endl;               // 换行
    }
    return 0;
}
