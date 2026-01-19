#include <iostream> //cin & cout
#include <cstring>  //memset & strlen
#include <cstdio>   //sscanf & sprintf
using namespace std;

int main()
{
    char a;
    char s[100], b[10];
    int n, c, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        if (b[0] >= 'a' && b[0] <= 'c')
        {
            a = b[0];
            cin >> c >> d;
        }
        else
        {
            sscanf(b, "%d", &c);
            cin >> d;
        }
        memset(s, 0, sizeof(s));
        if (a == 'a')
            sprintf(s, "%d+%d=%d", c, d, c + d);
        else if (a == 'b')
            sprintf(s, "%d-%d=%d", c, d, c - d);
        else if (a == 'c')
            sprintf(s, "%d*%d=%d", c, d, c * d);
        cout << s << endl
             << strlen(s) << endl;
    }
    return 0;
}
