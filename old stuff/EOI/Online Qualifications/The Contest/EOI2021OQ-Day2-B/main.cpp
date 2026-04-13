#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, q, k;
        std::cin >> n >> q >> k;

        std::vector<long long> l(n);
        std::vector<long long> r(n);

        for (int i = 0; i < n; i++)
            std::cin >> l[i] >> r[i];

        long long x;
        if (k == 1)
        {
            for (int j = 0; j < q; j++)
            {
                long long cnt = 0;
                std::cin >> x;
                bool is_free = 1;
                for (int i = 0; i < n; i++)
                {
                    if (x < l[i] || x > r[i])
                    {
                        std::cout << 1 << std::endl;
                        is_free = 0;
                        break;
                    }
                }
                if (is_free)
                    std::cout << 0 << std::endl;
            }
        }
        else
        {
            for (int j = 0; j < q; j++)
            {
                long long cnt = 0;
                std::cin >> x;
                for (int i = 0; i < n; i++)
                {
                    if (x < l[i])
                        cnt += l[i] - x;
                    else if (x > r[i])
                        cnt += x - r[i];
                }
                std::cout << cnt << std::endl;
            }
        }
    }
}
