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
    ll n, x;
    cin >> n >> x;
    rep(i, 0, n)
    {
        if (i!=x) cout << i << ' ';
    }
    if (x < n) cout << x;
    cout << endl;
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