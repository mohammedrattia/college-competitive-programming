#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m, k;
ll arr[10000];

/*ll dfs(ll i, ll l)
{
    if (l == m || i == m+k)
        return 0;
    ll ret = 0;
    ret += max(dfs(i+1, l), dfs(i+1, l+1) + arr[i]);

    return ret;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    ll arr[m+k], x, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i < k+m)
            cin >> arr[i];
        else cin >> x;
    }
    sort(arr, arr+m+k, greater<int>());
    for (ll i = 0; i < m; i++)
    {
        ans += arr[i];
    }
    cout << ans;
}
