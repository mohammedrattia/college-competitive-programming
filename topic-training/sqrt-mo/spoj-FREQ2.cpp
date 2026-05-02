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
const int SZ = 1e6 + 1;

// solution specific data structure
vll arr;
vector<int> freq, cnt;
ll ans;

void remove(int idx)
{
    cnt[freq[arr[idx]]]--;
    ans -= (freq[arr[idx]] == ans && cnt[freq[arr[idx]]] == 0);
    freq[arr[idx]]--;
    cnt[freq[arr[idx]]]++;
}
void add(int idx)
{
    cnt[freq[arr[idx]]]--;
    freq[arr[idx]]++;
    ans += (freq[arr[idx]] > ans);
    cnt[freq[arr[idx]]]++;
}
ll get_answer()
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

vector<ll> answers;
void mo_s_algorithm(vector<Query> &qu)
{
    answers = vector<ll>(qu.size());
    sort(qu.begin(), qu.end());

    int l = 0;
    int r = -1;
    // [l, r]
    for (Query q : qu)
    {
        while (l > q.l)
        {
            l--;
            add(l);
        }
        while (r < q.r)
        {
            r++;
            add(r);
        }
        while (l < q.l)
        {
            remove(l);
            l++;
        }
        while (r > q.r)
        {
            remove(r);
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
    int n, q;
    cin >> n >> q;
    block_size = sqrt(n) + 1;
    freq = vector<int>(SZ, 0);
    cnt = vector<int>(SZ, 0);
    cnt[0] = n;
    arr = vll(n);
    rep(i, 0, n) cin >> arr[i];

    vector<Query> qu(q);
    rep(i, 0, q)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].idx = i;
    }
    mo_s_algorithm(qu);
    rep(i, 0, q)
    {
        cout << answers[i] << endl;
    }
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
