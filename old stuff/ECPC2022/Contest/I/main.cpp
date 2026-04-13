#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 1; i < n; i++)

int main()
{
    freopen("good.in", "r", stdin);
    int k;
    string str;
    cin >> str >> k;
    int num = 1;
    char c;
    bool b = 0;
    rep(i, str.size())
    {
        if (str[i] != str[i-1])
        {
            if (num >= k)
            {
                c = str[i-1];
                b = 1;
                break;
            }
            else num = 0;
        }
        num++;
    }
    if (b)
        cout << "YES " << c << endl;
    else cout << "NO" << endl;
}
