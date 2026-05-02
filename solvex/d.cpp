// #pragma GCC optimize("O2")

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
    ll a, m, n;
    cin >> a >> m >> n;
    a++;
    vll arr(a), cons(a);
    rep(i, 0, m)
    {
        ll l, r;
        cin >> l >> r;
        rep(j, l, r)
        {
            arr[j] = 1;
        }
    }
    vector<pll> mods(n);
    rep(i, 0, n)
    {
        cin >> mods[i].F >> mods[i].S;
    }
    sort(all(mods));
    ll ans = 0;
    rep(i, 0, a)
    {
        if (arr[i])
        {
            ll val = INF;
            pll ins;
            vector<pll>::iterator it, rm = mods.end();
            for (it = mods.begin(); it != mods.end(); it++)
            {
                if (it->F > i)
                    break;
                ll cur = it->S * (i - it->F + 1);
                if (val > cur)
                {
                    rm = it;
                    val = cur;
                    ins.F = i;
                    ins.S = it->S;
                }
            }
            if (rm == mods.end())
            {
                cout << -1 << endl;
                return;
            }
            rep(j, rm->F, ins.F+1)
            {
                cons[j] = ins.S;
            }
            mods.erase(rm);
            mods.insert(lower_bound(all(mods), ins), ins);
        }
    }
    rep(i, 0, a)
    {
        ans += cons[i];
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
