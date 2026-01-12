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
    ll n;
    cin >> n;
    ll arr[2][n];
    rep(i, 0, 2)
            rep(j, 0, n)
                cin >>
        arr[i][j];

    ll t = 0, b = 0, ans = 1000000000;
    rep(i, 1, n)
    {
        t += arr[0][i];
    }
    rep(i, 0, n - 1)
    {
        ans = min(ans, max(b, t));
        t -= arr[0][i + 1];
        b += arr[1][i];
    }
    ans = min(ans, max(b, t));
    cout << ans << endl;
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
