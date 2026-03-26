#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int price;
    int day;
} Milk;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Milk> milks(m);
    for (int i = 0; i < m; i++)
    {
        cin >> milks[i].price >> milks[i].day;
    }
    sort(milks.begin(), milks.end(), [](Milk a, Milk b)
         { return a.price < b.price; });
    int total_money = 0;
    for (int j = 0; j < m; j++)
    {
        if (milks[j].day <= n)
        {
            n -= milks[j].day;
            total_money += milks[j].price * milks[j].day;
        }
        else
        {
            total_money += n * milks[j].price;
            break;
        }
    }
    cout << total_money << endl;
    return 0;
}