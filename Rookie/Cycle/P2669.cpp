#include <iostream>

int main() {
    int k, coin = 0, day = 0, i, j;
    std::cin >> k;
    for (i = 1; i <= k; i++) {
        for (j = 1; j <= i; j++) {
            coin += i;
            day++;
            if (day == k) {
                std::cout << coin;
                return 0;
            }
        }
    }
}
