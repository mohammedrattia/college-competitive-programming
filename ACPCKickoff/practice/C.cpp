#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
#define F first
#define S second
#define pr pair<long long, long long>
// #define endl '\n'

bool cmp(pr a, pr b)
{
    return a.F < b.F;
}

const ll mod = 132120577;

void solve()
{
    ll n;
    cin >> n;
    pr arr[n];
    ll diff[n];
    rep(i, 0, n)
    {
        cin >> arr[i].F >> arr[i].S;
    }
    sort(arr, arr+n);
    rep(i, 1, n)
    {
        arr[i].S += arr[i-1].S;
    }
    ll l = 0, r = 0;
    rep(i, 0, n)
    {
        diff[arr[0].F - arr[i].F] = (arr[0].S * arr[i].S)%mod;
    }
    rep(i, 0, n)
    {
        diff[arr[l].F - arr[i].F] = (arr[l].S * arr[i].S)%mod;
    }
    ll q;
    cin >> q;
    rep(i, 0, q)
    {
        cin >> l >> r;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}

