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

ll ans;
priority_queue<ll> pq;
vll pre, arr;

void remove(int l, int r)
{
    if ((r - l + 1) % 2 == 0)
        pq.push(arr[l] ^ arr[r]);
    else
        pq.push(pre[r + 1] ^ pre[l]);
}
void add(int l, int r)
{
    if ((r - l + 1) % 2 == 0)
        ans = max(ans, arr[l] ^ arr[r]);
    else
        ans = max(ans, pre[r + 1] ^ pre[l]);
}
int get_answer()
{
    return ans;
}

int block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> answers;
void mo_s_algorithm(vector<Query> queries)
{
    answers = vector<int>(queries.size());
    sort(queries.begin(), queries.end());

    int l = 0;
    int r = -1;
    for (Query q : queries)
    {
        while (l > q.l)
        {
            l--;
            add(l, r);
        }
        while (r < q.r)
        {
            r++;
            add(l, r);
        }
        while (l < q.l)
        {
            remove(l, r);
            l++;
        }
        while (r > q.r)
        {
            remove(l, r);
            r--;
        }
        answers[q.idx] = get_answer();
    }
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    block_size = sqrt(n) + 1;
    arr = vll(n);
    pre = vll(n + 1, 0);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n) pre[i + 1] = pre[i] ^ arr[i];

    ll q;
    cin >> q;
    vector<Query> qu(q);
    rep(i, 0, q)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].l--, qu[i].r--;
        qu[i].idx = i;
    }
    sort(all(qu));
    mo_s_algorithm(qu);
    rep(i, 0, q) cout << answers[i] << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
