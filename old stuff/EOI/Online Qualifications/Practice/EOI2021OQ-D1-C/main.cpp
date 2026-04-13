#include <iostream>
#include <vector>

int main()
{
    long long t, st;
    std::cin >> t >> st;
    if (st == 3)
    {

        while (t--)
        {
            int n;
            std::cin >> n;
            std::vector<int> a(n,0);
            int all_sad = 0;
            int max_sad = 0;
            int ones = 0;
            for (int i = 0; i < n; i++)
            {
                std::cin >> a[i];
                if (a[i] == 1)
                    ones++;
                else
                {
                    all_sad += ones;
                    max_sad = ones;
                }
            }
            std::cout << all_sad - max_sad << std::endl;
        }
    }
}









