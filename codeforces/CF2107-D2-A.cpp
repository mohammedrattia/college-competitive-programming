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
    ll mx = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    ll ans[n] = {0};
    ll cnt = 0;
    rep(i, 1, mx+1)
    {
        rep(j, 0, n)
        {
            if (arr[j]%i==0)
            {
                ans[j] = 1;
                cnt++;
            }
        }
        if (cnt > 0 && cnt < n)
        {
            cout << "YES" << endl;
            rep(j, 0, n)
            {
                if (ans[j] == 1)
                    cout << 1 << ' ';
                else cout << 2 << ' ';
            }
            cout << endl;
            return;
        }
        cnt = 0;
        rep(j, 0, n)
        {
            ans[j] = 0;
        }
    }
    cout << "NO" << endl;
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
