#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pair<long long, long long> pr


void solve()
{
    int n;
    cin >> n;
    set<ll> arr;
    ll x;
    rep(i, 0, n)
    {
        cin >> x;
        arr.insert(x);
    }
    cout << arr.size() << endl;
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