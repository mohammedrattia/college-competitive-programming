#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pr pair<long long, long long>
#define endl '\n'

void solve()
{
    ll n;
    char c;
    cin >> n >> c;
    string str;
    cin >> str;
    bool f = 1;
    rep(i, 0, n)
    {
        if (str[i] != c)
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << 0 << endl;
        return;
    }
    rep(i, n / 2, n)
    {
        if (str[i] == c)
        {
            cout << 1 << '\n'
                 << i + 1 << endl;
            return;
        }
    }
    cout << 2 << '\n'
         << n << ' ' << n - 1 << endl;
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
