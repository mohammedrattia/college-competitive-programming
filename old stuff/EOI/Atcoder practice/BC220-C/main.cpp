#include <iostream>
#include <vector>

int main()
{
    long long n, x;
    std::cin >> n;
    std::vector<long long> a(n);
    long long k = 0, sum = 0;
    for (auto &e : a)
    {
        std::cin >> e;
        sum += e;
    }
    std::cin >> x;
    long long ans = (x / sum)*n;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        k = i;
        if (sum >= x)
            break;
    }
    std::cout << ans + k;
    return 0;
}
