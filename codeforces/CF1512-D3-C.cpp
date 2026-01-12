#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pr pair<long long, long long>
// #define endl '\n'

void solve()
{
    ll a, b;
    cin >> a >> b;
    string str;
    cin >> str;
    if (a % 2 && b % 2)
    {
        cout << -1 << endl;
        return;
    }
    ll n = a + b;
    if ((a % 2 && str[n / 2] == '1') || (b % 2 && str[n / 2] == '0'))
    {
        cout << -1 << endl;
        return;
    }
    if (a % 2)
    {
        str[n / 2] = '0';
        a--;
    }
    else if (b % 2)
    {
        str[n / 2] = '1';
        b--;
    }

    rep(i, 0, n / 2)
    {
        if (str[i] != '?' && str[n - i - 1] != '?')
        {
            if (str[i] != str[n - i - 1])
            {
                cout << -1 << endl;
                return;
            }
            (str[i] == '0' ? a -= 2 : b -= 2);
        }
        else if (str[i] == '0' || str[n - i - 1] == '0')
        {
            str[i] = '0';
            str[n - i - 1] = '0';
            a -= 2;
        }
        else if (str[i] == '1' || str[n - i - 1] == '1')
        {
            str[i] = '1';
            str[n - i - 1] = '1';
            b -= 2;
        }
        if (a < 0 || b < 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    rep(i, 0, n / 2)
    {
        if (str[i] == '?')
        {
            if (a - 2 >= 0)
            {
                str[i] = '0';
                str[n - i - 1] = '0';
                a -= 2;
            }
            else if (b - 2 >= 0)
            {
                str[i] = '1';
                str[n - i - 1] = '1';
                b -= 2;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    cout << str << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
