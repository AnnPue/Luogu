#include <iostream>

int isPrime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    int i = 2;
    for (; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    std::cin >> n;
    int s[100] = {0};
    int i = 0;
    for (; i < n; ++i)
    {
        std::cin >> s[i];
        if (isPrime(s[i]))
        {
            std::cout << s[i] << ' ';
        }
    }
    return 0;
}