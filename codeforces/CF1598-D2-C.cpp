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
    cin >> n;
    ll arr[n];
    double avg = 0;
    ll k;
    rep(i, 0, n)
    {
        cin >> arr[i];
        avg += arr[i];
    }
    avg = (double)avg / n;
    k = avg * 2;
    if (abs(k - avg * 2) > 0.0001)
    {
        cout << 0 << endl;
        return;
    }
    sort(arr, arr + n);
    ll cnt = 0;
    rep(i, 0, n)
    {
        ll rem = k - arr[i];
        ll l = lower_bound(arr, arr + n, rem) - arr;
        ll r = upper_bound(arr, arr + n, rem) - arr;
        if (l != r)
        {
            cnt += r - l;
            if (i >= l && i < r)
                cnt--;
        }
    }
    cout << cnt / 2 << endl;
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
