#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;
        if ((n - m) < k)
            std::cout << "NO" << std::endl;
        else if (m == 1)
        {

            std::cout << "YES" << std::endl;

            std::cout << 0 << " ";

            for (int j = 2; j < m + k; j++)
                    std::cout << j << " ";

            std::cout << 1 << " ";

            for (int i = m + k; i < n; i++)
            {
                std::cout << i << " \n"[i == n-1];
            }
        }
        else
        {
            std::cout << "YES" << std::endl;
            for (int i = 0; i < n; i++)
            {
                if (i == m)
                {
                    for (int j = i + 1; j < m + k; j++)
                        std::cout << j << " ";

                    std::cout << i << " ";
                    i += k-1;
                    if (i == n - 1)
                        std::cout << std::endl;
                }
                else
                    std::cout << i << " \n"[i == n-1];
            }
        }
    }
}
