#include <iostream>
#include <string>
#include <vector>
#include <utility>

char s[201][201], t[201][201];
int n, cnt_s = 0,cnt_t = 0;

void rot()
{
    static char c[200][200];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[j][n - i] = t[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = c[i][j];
}
bool solve()
{
    std::vector<std::pair<int,int>> ti, si;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '#') si.push_back({i, j});
            if (t[i][j] == '#') ti.push_back({i, j});
        }
    for (int i = 0; i < cnt_s; i++)
        if (si[i].first - ti[i].first != si[0].first - ti[0].first || si[i].second - ti[i].second != si[0].second - ti[0].second)
            return false;
    return true;
}
int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
        for (int j = 0; j < n; j++)
            cnt_s += (s[i][j] == '#');
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> t[i];
        for (int j = 0; j < n; j++)
                cnt_t += (t[i][j] == '#');
    }

    if (cnt_s != cnt_t)
    {
        std::cout << "No";
        return 0;
    }
    if (cnt_s == 0)
    {
        std::cout << "Yes";
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        if(solve())
        {
            std::cout << "Yes";
            return 0;
        }
        rot();
    }
    std::cout << "No";
    return 0;
}
