#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int k;
    std::string a, b;
    std::cin >> k >> a >> b;

    long long anum = 0, bnum = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        long long num = (int)(a[i] - '0');
        long long power = std::pow(k, (int)a.size() - i - 1);
        anum += num * power;
    }

    for (int i = 0; i < (int)b.size(); i++)
    {
        long long num = (int)(b[i] - '0');
        long long power = std::pow(k, (int)b.size() - i - 1);
        bnum += num * power;
    }

    long long ans = anum * bnum;
    std::cout << ans;
    return 0;
}
