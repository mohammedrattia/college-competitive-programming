#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
#define F first
#define S second
#define pr pair<long long, long long>
#define vl vector<long long>
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll freq[n + 1] = {0};
    unordered_set<ll> u;
    rep(i, 0, n)
    {
        cin >> arr[i];
        u.insert(arr[i]);
        freq[arr[i]]++;
    }
    ll cnt = u.size(), k = u.size();

    unordered_set<ll> cur;
    ll ans = 1;
    rrep(i, n - 1, 0)
    {
        if (cur.size() == k)
        {
            cur.clear();
            k = cnt;
            ans++;
        }
        freq[arr[i]]--;
        if (freq[arr[i]] == 0)
            cnt--;
        cur.insert(arr[i]);
    }
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
