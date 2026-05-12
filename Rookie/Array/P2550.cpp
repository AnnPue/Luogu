#include <set>
#include <array>
#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    std::array<int, 7> how_many_bonus = {0};
    std::set<int> bonusSet;
    for (int i = 0; i < 7; ++i)
    {
        int bouns_num;
        std::cin >> bouns_num;
        bonusSet.insert(bouns_num);
    }
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < 7; ++j)
        {
            int lottery_num;
            std::cin >> lottery_num;
            if (bonusSet.count(lottery_num))
                ++count;
        }
        how_many_bonus[7 - count]++;
    }
    for (int n : how_many_bonus)
    {
        std::cout << n << ' ';
    }
}