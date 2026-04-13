#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string ans = "";
        for (int i = n-1; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                ans = (char)((int)(str[i-1]-'1')+(int)(str[i-2]-'0')*10 + 'a') + ans;
                i-=2;
            }
            else ans = (char)((int)(str[i]-'1') + 'a') + ans;
        }
        cout << ans << endl;
    }
}
