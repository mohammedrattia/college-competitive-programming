#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pr pair<long long, long long>
// #define endl '\n'
vector<vector<ll>> arr;
int visited[200000];

int dfs(int i)
{
    if (visited[i])
        return 0;
    if (arr[i].empty())
        return 1;
    ll ret = 0;
    for (auto e:arr[i]) ret += dfs(e);
    return ret;
}

void solve()
{
    ll n;
    cin >> n;
    ll nums[n];
    memset(visited, 0, sizeof(visited));
    rep(i, 0, n) cin >> nums[i];
    arr = vector<vector<ll>>(n);
    if (nums[0] > nums[1]) arr[0].push_back(1);
    rep(i, 1, n-1)
    {
        if (nums[i] >= nums[i-1]) arr[i].push_back(i-1);
        if (nums[i+1] <= nums[i]) arr[i].push_back(i+1);
    }
    if (nums[n-1] > nums[n-2]) arr[n-1].push_back(n-2);
    ll ans = 0;
    rep(i,0,n)
    {
        if (!visited[i] && !arr[i].empty())
            ans += dfs(i);
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
