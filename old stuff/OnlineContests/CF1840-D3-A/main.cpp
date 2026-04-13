#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, ans = "";
        cin >> s;
        char c = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] == c)
            {
                ans += c;
                c = s[i+1];
                i++;
            }
        }
        cout << ans << endl;
    }
}
