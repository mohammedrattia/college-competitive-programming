#include <iostream>

#define ll long long

int main()
{
    ll t, st;
    std::cin >> t >> st;
    while (t--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        std::cout << (x > (z / y) ? (z / y) : x) << std::endl;
    }
    return 0;
}
