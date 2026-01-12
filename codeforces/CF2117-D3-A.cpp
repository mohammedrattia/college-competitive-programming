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
    ll arr[n], r = -1, l = -1;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] == 1 && l == -1)
            l = i;
        if (arr[i] == 1)
            r = i;
    }
    cout << (r - l + 1 <= x ? "YES" : "NO") << endl;
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
