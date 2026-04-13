#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string color;
    cin >> n >> m >> color;

    vector<string> str(n + 2);
    int l = -1, r = -1, u = -1, d = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];

        l = (l == -1 ? str[i].find_first_of(color) : l);
        u = ((u == -1 && l != -1) ? i : u);
        r = (str[i].find_last_of(color) != -1 ? str[i].find_last_of(color) : r);
        d = (str[i].find_last_of(color) != -1 ? i : d);
    }
    set<char> deputy;
    if (0 <= u - 1)
        for (int i = l; i <= r; i++)
            deputy.insert(str[u - 1][i]);
    if (n > d + 1)
        for (int i = l; i <= r; i++)
            deputy.insert(str[d + 1][i]);
    if (0 <= l - 1)
        for (int j = u; j <= d; j++)
            deputy.insert(str[j][l - 1]);
    if (m > r + 1)
        for (int j = u; j <= d; j++)
            deputy.insert(str[j][r + 1]);

    if (deputy.find('.') != deputy.end())
        cout << deputy.size() - 1;
    else
        cout << deputy.size();
}
