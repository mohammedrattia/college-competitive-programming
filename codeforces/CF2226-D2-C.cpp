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
const int SZ = 1e5 + 1;

ll printDivisors(int n)
{
    vector<int> divisors;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                divisors.push_back(i);
            }
            else
            {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }
    if (divisors.size() <= 1)
        return divisors.size();
    sort(all(divisors));
    return min(*(divisors.end() - 1) - *(divisors.end() - 2), n/2);
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    vector<pll> div(n);
    rep(i, 0, n)
    {
        div[i].F = printDivisors(arr[i]);
        div[i].S = arr[i];
    }
    sort(all(div));
    ll cur = 0;
    set<int> ans;
    rep(i, 0, n)
    {
        while (ans.find(cur) != ans.end())
        {
            cur++;
        }
        if (cur < div[i].F)
        {
            ans.insert(cur);
            cur++;
        }
        else
        {
            ans.insert(div[i].S);
        }
    }
    cur = 0;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        if (*it == cur)
            cur++;
    }
    cout << cur << endl;
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}
