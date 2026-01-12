#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

ll k, x;

ll numEmojis(ll m)
{
    if (m <= k)
    {
        return m * (m + 1) / 2;
    }
    else
    {
        ll r = (2 * k - 1) - m;
        return k * (k + 1) / 2 + k * (k - 1) / 2 - r * (r + 1) / 2;
    }
}

void solve()
{
    cin >> k >> x;

    ll l = 0, r = 2 * k - 1;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (numEmojis(mid) >= x)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}