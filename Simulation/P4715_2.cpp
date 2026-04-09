#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    n = 1 << n;
    int half = n >> 1;
    int max1 = 0, max2 = 0;
    int id1, id2;
    for (int i = 1; i <= half; i++)
    {
        int power;
        cin >> power;
        if (power > max1)
        {
            max1 = power;
            id1 = i;
        }
    }
    for (int i = half + 1; i <= n; i++)
    {
        int power;
        cin >> power;
        if (power > max2)
        {
            max2 = power;
            id2 = i;
        }
    }
    if (max1 > max2)
        cout << id2;
    else
        cout << id1;
    return 0;
}