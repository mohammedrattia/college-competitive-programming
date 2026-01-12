#include <bits/stdc++.h>

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second

using namespace std;

void solve()
{
    int n;
    cin >> n;
    ll arr[n];
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<>());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && arr[i]%2 == 0) ans += arr[i];
        if (i % 2 == 1 && arr[i]%2 == 1) ans -= arr[i];
    }
    if (ans > 0) cout << "Alice" << endl;
    else if (ans < 0) cout << "Bob" << endl;
    else cout << "Tie" << endl;
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