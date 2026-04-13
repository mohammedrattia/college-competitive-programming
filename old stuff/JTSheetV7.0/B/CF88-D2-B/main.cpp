#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    string str[30];
    vector<int> rows;
    vector<int> cols;
    string spr_str = "";
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        spr_str += str[i];
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == 'S')
            {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    map<char, double> mp;

    for (int k = 0; k < cols.size(); k++)
    {
        int col = cols[k];
        int row = rows[k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (str[i][j] >= 'a')
                {
                    if (mp[str[i][j]] != 0)
                        mp[str[i][j]] = min(sqrt(pow(i-row, 2)+pow(j-col, 2)), mp[str[i][j]]);
                    else
                        mp[str[i][j]] = sqrt(pow(i-row, 2)+pow(j-col, 2));
                }
            }
        }
    }
    int q;
    cin >> q;
    string txt;
    cin >> txt;
    int num = 0;
    for (int i = 0; i < q; i++)
    {
        if (txt[i] < 'a')
        {
            if (rows.size() == 0)
            {
                cout << -1;
                return 0;
            }
            else if (!mp.count((char)(txt[i] + ('a' - 'A'))))
            {
                cout << -1;
                return 0;
            }
            else if (mp[(char)(txt[i] + ('a' - 'A'))] > x)
            {
                num++;
            }
        }
        else if (spr_str.find(txt[i]) == std::string::npos)
        {
            cout << -1;
            return 0;
        }
    }
    cout << num;
}
