#include <iostream>
int main() {
    int N, L, n, sum = -4, len = 0;
    std::cin >> N >> L;
    while(!(std::cin >> n).eof())
        if((sum += n + 1) > L*4) break;
        else len++;
    std::cout << len;
}