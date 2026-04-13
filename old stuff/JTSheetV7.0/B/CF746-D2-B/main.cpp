#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str, ans = "";
    cin >> str;
    bool b = 1;
    if (n%2)
        b = 0;
    for (int i = 0; i < n; i++)
    {
        if (b)
        {
            ans = str[i] + ans;
            b = 0;
        }
        else
        {
            ans = ans + str[i];
            b = 1;
        }
    }
    cout << ans;
}
