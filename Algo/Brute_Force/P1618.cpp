#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int b3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 1~9 全排列

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool unsov = true;

    do
    {
        // 从全排列中取出三个三位数
        int a1 = 100 * b3[1] + 10 * b3[2] + b3[3];
        int b1 = 100 * b3[4] + 10 * b3[5] + b3[6];
        int c1 = 100 * b3[7] + 10 * b3[8] + b3[9];

        if (a1 * b == b1 * a && b1 * c == c1 * b)
        {
            unsov = false;
            printf("%d %d %d\n", a1, b1, c1);
        }
    } while (next_permutation(b3 + 1, b3 + 10)); // 生成 1~9 全排列。next_permutation库函数

    if (unsov)
        printf("No!!!");
    return 0;
}
