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
const int SZ = 1e5 + 1;

// STRING HASHING
const int N = 1e6 + 5, P1 = 31, P2 = 37, M = 1e9 + 7;
int pw1[N], pw2[N], inv1[N], inv2[N];
int mul(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a * 1LL * b) % M;
}
int add(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a + b) % M;
}
int fastPower(int base, int power)
{
    if (!power)
        return 1;
    int ret = fastPower(base, power >> 1);
    ret = mul(ret, ret);
    if (power % 2)
        ret = mul(ret, base);
    return ret;
}
void pre()
{
    pw1[0] = inv1[0] = pw2[0] = inv2[0] = 1;
    int mulInv1 = fastPower(P1, M - 2);
    int mulInv2 = fastPower(P2, M - 2);
    for (int i = 1; i < N; i++)
    {
        pw1[i] = mul(pw1[i - 1], P1);
        pw2[i] = mul(pw2[i - 1], P2);
        inv1[i] = mul(inv1[i - 1], mulInv1);
        inv2[i] = mul(inv2[i - 1], mulInv2);
    }
}
struct Hash
{
    vector<pair<int, int>> prefixHash;
    Hash(string s)
    {
        prefixHash = vector<pair<int, int>>(s.size(), {0, 0});
        for (int i = 0; i < (int)s.size(); i++)
        {
            prefixHash[i].F = mul(s[i] - 'a' + 1, pw1[i]);
            prefixHash[i].S = mul(s[i] - 'a' + 1, pw2[i]);
            if (i)
                prefixHash[i] = {add(prefixHash[i].F, prefixHash[i - 1].F),
                                 add(prefixHash[i].S, prefixHash[i - 1].S)};
        }
    }
    pair<int, int> getHashVal() { return prefixHash.back(); }
    pair<int, int> getRangeHashVal(int l, int r)
    {
        return {mul(add(prefixHash[r].F, -(l ? prefixHash[l - 1].F : 0)), inv1[l]),
                mul(add(prefixHash[r].S, -(l ? prefixHash[l - 1].S : 0)), inv2[l])};
    }
};
ll pair_hash(pair<int, int> a) { return ((ll)a.F << 32ll) + (ll)a.S; }

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, m, k;
    string str, p;
    getline(cin,  str);
    getline(cin, p);
    n = str.size(), m = p.size();
    cin >> k;
    Hash hashs = Hash(str);
    Hash hashp = Hash(p);

    int l = 0, r = m - 1;
    pii ans = {-1, -1};
    while (l <= r)
    {
        int mid = (l + r) / 2;
        pii v = hashp.getRangeHashVal(0, mid);
        int cnt = 0;
        rep(i, 0, n - mid)
        {
            pii u = hashs.getRangeHashVal(i, i + mid);
            if (v == u)
                cnt++;
        }
        if (cnt < k)
            r = mid - 1;
        else
        {
            l = mid + 1;
            ans = v;
        }
    }
    if (ans == MP(-1, -1))
        cout << "IMPOSSIBLE" << endl;
    else
        cout << p.substr(0, l) << endl;
}

int main()
{
    FAST;
    pre();
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
