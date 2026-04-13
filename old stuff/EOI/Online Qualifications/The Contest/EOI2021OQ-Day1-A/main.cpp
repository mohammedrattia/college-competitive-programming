#include <iostream>

#define ll long long

int main()
{
    ll t, st;
    std::cin >> t;
    while (t--)
    {
        ll n, k;
        std::cin >> n >> k;
        if ((n - (k - 1)) % 2 == 0)
            std::cout << k - 1 << std::endl;
        else
            std::cout << k << std::endl;
    }
}
