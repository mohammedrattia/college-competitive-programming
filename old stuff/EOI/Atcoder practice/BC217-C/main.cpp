#include <iostream>
#include <vector>

int main()
{
    int n, p;
    std::cin >> n;
    std::vector<int> q(n);
    q.reserve(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p;
        q[p - 1] = i + 1;
    }
    for (int i = 0; i < n; i++)
        std::cout << q[i] << " ";
    return 0;
}
