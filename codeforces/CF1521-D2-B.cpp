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
    ll arr[n];
    ll mn = 1000000005, idx = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] <= mn)
        {
            mn = arr[i];
            idx = i;
        }
    }
    const ll l = 1000000007, h = 1000000009;
    bool last = 0;
    cout << n - 1 << endl;
    rep(i, 0, n)
    {
        last = !last;
        if (i == idx)
            continue;
        cout << i + 1 << ' ' << idx + 1 << ' ' << (l * (last) + h * (!last)) << ' ' << mn << endl;
    }
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