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
    ll n, k;
    cin >> n >> k;
    ll l = k+1, h = 0;
    ll a[n], b[n];
    rep(i, 0, n)
    {
        cin >> a[i];
        l = min(l, a[i]);
        h = max(h, a[i]);
    }
    rep(i, 0, n)
    {
        cin >> b[i];
    }
    ll x = -1;
    rep(i, 0, n)
    {
        if (x == -1 && b[i] != -1)
        {
            x = a[i] + b[i];
            break;
        }
    }
    rep(i, 0, n)
    {
        if (b[i] != -1 && a[i]+b[i] < h)
        {
            cout << 0 << endl;
            return;
        }
        if (x != -1 && b[i] != -1 && a[i]+b[i] != x)
        {
            cout << 0 << endl;
            return;
        }
        if (x != -1 && b[i] == -1 && x-a[i] > k)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (x != -1)
        cout << 1 << endl;
    else
        cout << k-(h-l)+1 << endl;
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
