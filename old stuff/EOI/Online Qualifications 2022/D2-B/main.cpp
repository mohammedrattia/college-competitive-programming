#include <iostream>
#include<utility>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> adj;
vector<ll> ans;
ll arr[1005];

void dfs(ll cur)
{
    ans.push_back(cur);
    if (adj[cur].size() == 0)
        return;

    for (auto &i : adj[cur])
    {
        dfs(i.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t, st;
    cin >> t >> st;
    while (t--)
    {
        ll n, a, b, q;
        cin >> n >> q;
        adj.clear();
        adj = vector<vector<pair<ll, ll>>>(n+5);
        for (ll i = 0; i < n-1; i++)
        {
            cin >> a >> b;
            adj[a].push_back(make_pair(0, b));
        }
        for (ll i = 0; i < q; i++)
        {
            cin >> arr[i];
        }
        if (true)
        {
            ll root = 0;
            dfs(1);
            for (ll i = 0; i < q; i++)
            {
                root++;
                for (ll j = 0; j < n; j++)
                {
                    cout << ans[j] << ' ';
                }
                cout << endl;
            }
        }
    }
}
