// #pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <iomanip>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
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
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

// OTHER DEFINES
#define PI 3.14159265358979323846
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
const int SZ = 2e6 + 1;

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, q;
    cin >> n;
    vll arr(n), change(n, -1);
    rep(i, 0, n) cin >> arr[i];

    cin >> q;
    ll p = -1, root = sqrt(q) + 1;
    vector<pair<ll, ll>> qu;

    rep(i, 0, q)
    {
        ll a, x, c;
        cin >> c;
        if (c == 1)
        {
            cin >> a >> x;
            a--;
            auto it = lower_bound(all(qu), MP(a, 0ll));
            if (it != qu.end() && it->F == a)
                it->S = x;
            else qu.insert(it, MP(a, x));
            change[a] = x;
        }
        else
        {
            cin >> x;
            p = max(p, x);
            for (auto &e : qu)
            {
                e.S = max(e.S, x);
                change[e.F] = e.S;
            }
        }
        if (i % root == 0)
        {
            rep(i, 0, n)
            {
                if (change[i] == -1)
                    arr[i] = max(arr[i], p);
                else
                    arr[i] = change[i];
            }
            p = -1;
            change = vll(n, -1);
            qu.clear();
        }
    }
    rep(i, 0, n)
    {
        if (change[i] == -1)
            arr[i] = max(arr[i], p);
        else
            arr[i] = change[i];
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
