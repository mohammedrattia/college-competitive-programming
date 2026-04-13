#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    if (x < 40)
        std::cout << 40 - x;
    else if (x < 70)
        std::cout << 70 - x;
    else if (x < 90)
        std::cout << 90 - x;
    else
        std::cout << "expert";
    return 0;
}
