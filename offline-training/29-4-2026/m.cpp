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
#define int ll
void solve()
{
    int n ; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<pair<int, int >> b(n, {-1,-1});
    for(int i = 0; i < n; i ++) {
        if (a[i] + i < n) {
            b[i].first = a[i] + i;
        }
        if(i - a[i] >=0) b[i].second = i - a[i];
    }

    int c1 = 0, c2 = 0;
    for(int i=0; i<n; i++) {
        if (b[i].first == b[0].first or b[i].second == b[0].first) c1 ++;
        if (b[i].first == b[n - 1].second or b[i].second == b[n - 1].second) c2 ++;
    }
    if (c1 == c2 && b[0].F != b[n-1].S) cout << -1;
    else  if (c1 == n - 1) cout << b[0].first + 1;
    else if (c2 == n - 1) cout << b.back().second + 1;
    else cout << -1;
    cout << '\n';
}

signed main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}