#include <iostream>

using namespace std;

int solve()
{
    string str[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> str[i];
    }

    int dirx[4] = {1, -1, 1, -1};
    int diry[4] = {-1, 1, 1, -1};


    for (int i = 1; i < 8-1; i++)
    {
        for (int j = 1; j < 8-1; j++)
        {
            if (str[i][j] == '#')
            {
                bool b = 1;
                for (int k = 0; k < 4; k++)
                {
                    b &= str[i+dirx[k]][j+diry[k]];
                }
                if (b)
                {
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
