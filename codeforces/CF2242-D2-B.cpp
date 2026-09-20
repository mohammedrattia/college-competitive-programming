// #pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>> using ordered_set = ordered_map<K, null_type, Comp>;

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
#define FAST                                                                                       \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 2e5 + 1;

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    ll idx1 = -1, idx2 = -1, good = 0, bad = 0, diff = INF;
    rep(i, 0, n)
    {
        cin >> arr[i];
        good += (arr[i] == 1);
        bad += (arr[i] != 1);
        if (good >= bad && idx1 == -1)
            idx1 = i;
        if (good - bad < diff && good >= bad && diff)
        {
            diff = good - bad;
            idx2 = i;
        }
    }
    if (idx1 == -1 && idx2 == -1)
    {
        cout << "NO" << endl;
        return;
    }
    ll val1 = -1, val2 = -1;
    good = 0, bad = 0;
    rep(i, idx1 + 1, n)
    {
        good += (arr[i] != 3);
        bad += (arr[i] == 3);
        if (good >= bad && val1 == -1)
        {
            val1 = i;
            break;
        }
    }
    good = 0, bad = 0;
    rep(i, idx2 + 1, n)
    {
        good += (arr[i] != 3);
        bad += (arr[i] == 3);
        if (good >= bad && val2 == -1)
        {
            val2 = i;
            break;
        }
    }
    if ((val1 < n - 1 && val1 > 0) || (val2 < n - 1 && val2 > 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}
