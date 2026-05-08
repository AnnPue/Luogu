#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
struct Man
{
    int time;
    short sn;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Man> men(n);
    for (int i = 0; i < n; ++i)
    {
        men[i].sn = i + 1;
        std::cin >> men[i].time;
    }
    // 接水用时少的人排在前面
    std::sort(men.begin(), men.end(), [](Man a, Man b)
              {
        if(a.time!=b.time)
            return a.time < b.time;
        // 如果两个人接水的时间相同，编号更小的人应当排在前面
        return a.sn < b.sn; });

    long long sum = 0;
    int i = 0;
    for (auto m : men)
    {
        std::cout << m.sn << ' ';
        sum += m.time * (n - 1 - i);
        ++i;
    }
    std::cout << std::endl;

    double avg = sum / (double)n;
    std::cout << std::fixed << std::setprecision(2) << avg;
}