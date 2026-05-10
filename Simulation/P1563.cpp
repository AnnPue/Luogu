// [NOIP 2016 提高组] 玩具谜题
#include <iostream>
#include <vector>
#include <utility> // for std::pair

int main()
{
    int n, m; // n: 小人数量；m: 指令数
    std::cin >> n >> m;
    // first: 小人朝向。0：朝圈内；1：朝圈外
    // second: 小人名字
    std::vector<std::pair<char, std::string>> men;
    for (int i = 0; i < n; ++i)
    {
        char ori;
        std::string name;
        std::cin >> ori >> name;
        men.emplace_back(ori, name);
    }
    char move;          // 数数的方向。0：向左数；1：向右数
    int step, tman = 0; // step: 数的步数；tman: 当前小人编号（0~n-1）
    while (m--)
    {
        std::cin >> move >> step;
        // 小人朝外且向左数 或 小人朝内且向右数 代表按逆时针方向数
        // 小人朝内且向左数 或 小人朝外且向右数（同或关系）代表按顺时针方向数
        if (move == men[tman].first)
        { // 若为顺时针，则步数为负
            step = -step;
        }
        int x = tman + step;
        tman = (x % n + n) % n; // 正负数统一的取模公式
    }
    std::cout << men[tman].second;
}