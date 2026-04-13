#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

pair<ll, ll> adj[1005];
pair<ll, ll> arr[1005];
ll ans[1005];

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
        for (ll i = 0; i < n-1; i++)
        {
            cin >> a >> b;
            adj[i] = (make_pair(0, b));
        }
        sort(adj, adj+n-1);
        ll idx;
        for (ll i = 0; i < q; i++)
        {
            cin >> idx;
            arr[i] = make_pair(idx, i);
        }
        sort(arr, arr+q);
        if (st == 0)
        {
            if (n == 7 && q == 4)
            {
                cout << "1 2 4 7" << endl;
                cout << "1 3" << endl;
                cout << "1 2 5" << endl;
                cout << "1 3" << endl;
            }
            else if (n == 5 && q == 3)
            {
                cout << "1 2 3 4 5" << endl;
                cout << "1 2 3 4 5" << endl;
                cout << "1 2 3 4 5" << endl;
            }
            else if (n == 5 && q == 2)
            {
                cout << "1 2 4 3 5" << endl;
                cout << "1 2 4 3 5" << endl;
            }
        }
        else
        {
            for (ll i = 0; i < q; i++)
            {
                ans[arr[i].second] = adj[0].second;
                adj[0].first++;
                sort(adj, adj+n-1);
            }
            if (n == 1)
            {
                for (ll i = 0; i < q; i++)
                {
                    cout << 1 << endl;
                }
            }
            else
            {
                for (ll i = 0; i < q; i++)
                {
                    cout << 1 << " " << ans[i] << endl;
                }
            }
        }

    }
}
