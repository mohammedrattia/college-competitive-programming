#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

ll n, k;

ll numOfDivisions(ll x, ll arr[])
{
    ll ret = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (sum + arr[i] <= x)
        {
            sum += arr[i];
        }
        else if (arr[i] > x)
        {
            return 1e15;
        }
        else
        {
            ret++;
            sum = arr[i];
        }
    }
    return ret;
}

int main()
{
    FAST;

    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll l = 0, r = 1e15;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (numOfDivisions(mid, arr) >= k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
}