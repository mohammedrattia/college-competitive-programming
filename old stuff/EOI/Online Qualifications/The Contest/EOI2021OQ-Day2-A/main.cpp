#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::string lamps[n];
        for (int i = 0; i < n; i++)
            std::cin >> lamps[i];

        for (int j = 0; j < m; j++)
        {
            bool is_alt = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (lamps[i][j] != lamps[i + 1][j])
                {
                    std::cout << '?';
                    is_alt = 1;
                    break;
                }
            }
            if (!is_alt)
                std::cout << lamps[0][j];
        }
        std::cout << std::endl;
    }
}
