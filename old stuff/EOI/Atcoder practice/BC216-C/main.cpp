#include <iostream>
#include <vector>

int main()
{
    long long n;
    std::cin >> n;
    std::vector<char> casts;
    while (n != 0)
    {
        if (n % 2 == 1)
            casts.push_back('A');
        casts.push_back('B');
        n /= 2;
    }
    for (int i = (int)(casts.size()) - 2; i >= 0; i--)
        std::cout << casts[i];
    return 0;
}
