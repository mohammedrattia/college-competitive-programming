// #pragma GCC optimize("O2")

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <numeric>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <climits>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <random>
#include <bitset>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

// BASIC DEFINES
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

// OTHER DEFINES
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)
#define dbg(x) cout << #x << " = " << x << '\n'
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, k, q;
    cin >> n >> k >> q;
    ordered_map<ll, ll> limits;
    limits[0] = k;
    limits[n] = k;
    ll total = n * k;

    rep(i, 0, q)
    {
        ll a, b, t;
        cin >> t;
        t--;
        if (t)
        {
            cin >> a;
            if (a == n)
            {
                cout << total << endl;
                continue;
            }
            ll val = limits.order_of_key(a);
            auto prev = limits.find_by_order(val - 1);
            auto curr = limits.find_by_order(val);
            auto next = limits.find_by_order(val + 1);

            ll dist = next->F - curr->F;
            total -= dist * curr->S;
            total += dist * prev->S;

            limits.erase(curr);
        }
        else
        {
            cin >> a >> b;
            if (a == n)
            {
                cout << total << endl;
                continue;
            }
            limits[a] = b;
            ll val = limits.order_of_key(a);
            auto prev = limits.find_by_order(val - 1);
            auto curr = limits.find_by_order(val);
            auto next = limits.find_by_order(val + 1);

            ll dist = next->F - curr->F;
            total += dist * curr->S;
            total -= dist * prev->S;
        }
        cout << total << endl;
    }
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
