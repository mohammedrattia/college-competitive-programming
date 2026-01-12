#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<ll, ll> mp;
    ll l = 0, r = 0, cnt = 0;
    while (r != n)
    {
        if (mp[arr[r]])
        {
            cnt += (r - l) * (r - l + 1) / 2;
            while (mp[arr[r]])
            {
                mp[arr[l++]]--;
            }
            cnt -= (r - l) * (r - l + 1) / 2;
        }
        mp[arr[r++]]++;
    }
    cnt += (r - l) * (r - l + 1) / 2;
    cout << cnt << endl;
}
