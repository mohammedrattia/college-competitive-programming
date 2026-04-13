#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    std::string alpha;
    int n;
    std::cin >> alpha >> n;

    std::vector<int> x(26);
    for (int i = 0; i < 26; i++)
        x[alpha[i] - 'a'] = i;

    std::vector<std::string> str(n);
    for (int i = 0; i < n; i++)
        std::cin >> str[i];

    std::vector<std::pair<std::vector<int>, std::string>> p(n);
    for (int i = 0; i < n; i++)
    {
        int s = (int)(str[i].size());
        std::vector<int> order(s);
        for (int j = 0; j < s; j++)
        {
            order[j] = x[str[i][j] - 'a'];
        }
        p[i] = std::make_pair(order, str[i]);
    }
    std::sort(p.begin(), p.end());

    for (int i = 0; i < n; i++)
        std::cout << p[i].second << std::endl;
    return 0;
}
