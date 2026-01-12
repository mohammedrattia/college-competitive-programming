#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

ll n, t;

ll numProducts(ll x, ll arr[])
{
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (cnt <= t)
        {
            cnt += x / arr[i];
        }
        else
        {
            return t;
        }
    }
    return cnt;
}

int main()
{
    FAST;

    cin >> n >> t;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll l = 0, r = 1e18;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (numProducts(mid, arr) >= t)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}