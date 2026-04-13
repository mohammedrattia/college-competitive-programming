#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string str[2];
    cin >> str[0] >> str[1];
    float p = 0;

    for (int i = 0; i < str[0].size(); i++)
    {
        for (int j = 0; j < str[1].size(); j++)
        {
            if (str[0][i] == str[1][j])
            {
                str[0].erase(str[0].begin() + i--);
                str[1].erase(str[1].begin() + j--);
                break;
            }
        }
    }
    if (str[1].find_first_of("+-") != string::npos || str[1] == "")
    {
        cout << fixed << setprecision(10) << p + (str[1] == "");
        return 0;
    }
    else
    {
        int num = 0;
        for (int i = 0; i < str[0].size(); i++)
        {
            if (str[0][i] == '+')
                num++;
        }
        int fac_n = 1, fac_r = 1, fac_dif = 1;
        for (int i = 2; i <= str[1].size(); i++)
        {
            fac_n *= i;
            if (i <= num)
                fac_r *= i;
            if (i <= str[1].size()-num)
                fac_dif *= i;
        }
        p = (fac_n/(fac_r*fac_dif))/pow(2, str[1].size());
        cout << fixed << setprecision(10) << p;
    }
}
