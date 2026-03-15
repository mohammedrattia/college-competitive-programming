// #pragma GCC optimize("O2")

#include <iostream>
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

using namespace std;

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

// GRID MOVEMENT
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// RANDOMIZATION
mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

// NUMBER THEORY II
namespace num_theory
{

    vll div(int n)
    {
        vll divisors;
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
        return divisors;
    }
    ll gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    ll lcm(ll a, ll b)
    {
        return (a * b) / gcd(a, b);
    }
    void moveEgcdStep(ll &a, ll &b, ll q)
    {
        ll next = a - q * b;
        a = b;
        b = next;
    }
    ll egcd(ll a, ll b, ll &x0, ll &y0)
    {
        ll r0 = a, r1 = b;
        ll x1 = y0 = 0, y1 = x0 = 1;
        while (r1 != 0)
        {
            ll q = r0 / r1;
            moveEgcdStep(x0, x1, q);
            moveEgcdStep(y0, y1, q);
            moveEgcdStep(r0, r1, q);
        }
        return r0;
    }
    ll modInverse(ll a, ll mod)
    {
        ll x, y;
        ll g = egcd(a, mod, x, y);
        if (g != 1)
            return -1;
        return (x + mod) % mod;
    }
    ll fastPower(ll a, ll p)
    {
        if (p == 0)
            return 1;
        if (p == 1)
            return a;
        ll halfPower = fastPower(a, p / 2);
        ll ret = halfPower * halfPower;
        if (p % 2 == 1)
            ret *= a;
        return ret;
    }
    ll modPower(ll a, ll p, ll mod)
    {
        if (p == 0)
            return 1;
        if (p == 1)
            return a;
        ll halfPower = modPower(a, p / 2, mod);
        ll ret = (halfPower * halfPower) % mod;
        if (p % 2 == 1)
            ret = (ret * a) % mod;
        return ret % mod;
    }
    ll modInverseFer(ll a, ll m)
    {
        return modPower(a, m - 2, m);
    }
    vll fact;
    void preFact(int n)
    {
        fact = vll(n);
        fact[0] = 1ll;
        fact[1] = 1ll;
        rep(i, 2, n)
        {
            fact[i] = (i * fact[i - 1]) % MOD;
        }
    }
    ll nCr(ll n, ll r)
    {
        if (r == 0ll)
            return 1ll;
        return (fact[n] * modInverseFer((fact[r] * fact[n - r]) % MOD, MOD)) % MOD;
    }
    ll nPr(ll n, ll r)
    {
        if (r == 0ll)
            return 1ll;
        return (fact[n] * modInverseFer(fact[n - r], MOD)) % MOD;
    }
    vll spf;
    void sieve(ll n)
    {
        spf = vll(n + 1, 1);
        spf[0] = 0;
        for (int i = 2; i <= n; i++)
        {
            if (spf[i] == 1)
            {
                for (int j = i; j <= n; j += i)
                {
                    if (spf[j] == 1)
                        spf[j] = i;
                }
            }
        }
    }
} // namespace num_theory

// SEGMENT TREE
namespace seg_tree
{
    template <typename T>
    struct SegTree
    {
        int size;
        vector<T> tree;
        T NEUTRAL_ELEMENT = {0};

        // Operation function (e.g., sum, min, max, gcd)
        T merge(T a, T b)
        {
            return {a.value + b.value};
        }
        T single(ll v)
        {
            return {v};
        }

        // Constructor
        SegTree(int n)
        {
            size = 1;
            while (size < n)
                size *= 2;
            tree.resize(2 * size, NEUTRAL_ELEMENT);
        }

        // Build from existing array
        void build(vector<ll> &a)
        {
            build(a, 0, 0, size);
        }

        void build(vector<ll> &a, int x, int lx, int rx)
        {
            if (rx - lx == 1)
            {
                if (lx < (int)a.size())
                    tree[x] = single(a[lx]);
                return;
            }
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        }

        // Point Update
        void set(int i, ll v)
        {
            set(i, v, 0, 0, size);
        }

        void set(int i, ll v, int x, int lx, int rx)
        {
            if (rx - lx == 1)
            {
                tree[x] = single(v);
                return;
            }
            int m = (lx + rx) / 2;
            if (i < m)
            {
                set(i, v, 2 * x + 1, lx, m);
            }
            else
            {
                set(i, v, 2 * x + 2, m, rx);
            }
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        }

        // Range Query
        T get(int l, int r)
        {
            return get(l, r, 0, 0, size);
        }

        T get(int l, int r, int x, int lx, int rx)
        {
            if (lx >= r || rx <= l)
                return NEUTRAL_ELEMENT;
            if (lx >= l && rx <= r)
                return tree[x];
            int m = (lx + rx) / 2;
            T s1 = get(l, r, 2 * x + 1, lx, m);
            T s2 = get(l, r, 2 * x + 2, m, rx);
            return merge(s1, s2);
        }
    };

    struct segtype
    {
        ll value;
    };
} // namespace seg_tree

// LAZY SEGMENT TREE
namespace lazy_seg
{
    template <typename T>
    struct SegTree
    {
        int size;
        vector<T> tree;
        vector<T> lazy;
        T NEUTRAL_ELEMENT = {0};
        T NO_OPERATION = {0};

        // Operation functions
        T merge(T a, T b)
        {
            return {a.value + b.value};
        }

        void apply(int x, T v, int len)
        {
            tree[x].value += v.value * len;
            lazy[x].value += v.value;
        }

        T single(ll v)
        {
            return {v};
        }

        // Constructor
        SegTree(int n)
        {
            size = 1;
            while (size < n)
                size *= 2;
            tree.resize(2 * size, NEUTRAL_ELEMENT);
            lazy.resize(2 * size, NO_OPERATION);
        }

        // Build from existing array
        void build(vector<ll> &a)
        {
            build(a, 0, 0, size);
        }

        void build(vector<ll> &a, int x, int lx, int rx)
        {
            if (rx - lx == 1)
            {
                if (lx < (int)a.size())
                    tree[x] = single(a[lx]);
                return;
            }
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        }

        // Range Update
        void modify(int l, int r, ll v)
        {
            modify(l, r, single(v), 0, 0, size);
        }

        void modify(int l, int r, T v, int x, int lx, int rx)
        {
            if (lx >= r || rx <= l)
                return;
            if (lx >= l && rx <= r)
            {
                apply(x, v, rx - lx);
                return;
            }
            propagate(x, lx, rx);
            int m = (lx + rx) / 2;
            modify(l, r, v, 2 * x + 1, lx, m);
            modify(l, r, v, 2 * x + 2, m, rx);
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        }

        void propagate(int x, int lx, int rx)
        {
            if (lazy[x].value == NO_OPERATION.value)
                return;

            int m = (lx + rx) / 2;
            apply(2 * x + 1, lazy[x], m - lx);
            apply(2 * x + 2, lazy[x], rx - m);

            lazy[x] = NO_OPERATION;
        }

        // Range Query
        T calc(int l, int r)
        {
            return calc(l, r, 0, 0, size);
        }
        T calc(int l, int r, int x, int lx, int rx)
        {
            if (lx >= r || rx <= l)
                return NEUTRAL_ELEMENT;
            if (lx >= l && rx <= r)
                return tree[x];
            propagate(x, lx, rx);
            int m = (lx + rx) / 2;
            T s1 = calc(l, r, 2 * x + 1, lx, m);
            T s2 = calc(l, r, 2 * x + 2, m, rx);
            return merge(s1, s2);
        }
    };

    struct segtype
    {
        ll value;
    };
} // namespace lazy_seg

// PERSISTENT SEGMENT TREE
namespace pers_seg
{
    struct segtype
    {
        ll value;
    };
    struct node
    {
        int left, right;
        segtype item;
    };
    struct SegTree
    {
        int size;
        const static int MAX_NODES = 4e6 + 5;
        vector<node> tree;
        vector<int> roots;
        int NEXT_NODE = 0;
        segtype NEUTRAL_ELEMENT = {0};

        // Operation function (e.g., sum, min, max, gcd)
        segtype merge(segtype a, segtype b)
        {
            return {a.value + b.value};
        }
        segtype single(ll v)
        {
            return {v};
        }

        // Node Manipulation
        int new_node(segtype v)
        {
            int id = NEXT_NODE++;
            tree[id].item = v;
            tree[id].left = tree[id].right = -1;
            return id;
        }

        int copy_node(int x)
        {
            int new_id = NEXT_NODE++;
            tree[new_id] = tree[x];
            return new_id;
        }

        // Constructor
        SegTree(int n)
        {
            size = 1;
            while (size < n)
                size *= 2;
            NEXT_NODE = 0;
            tree.resize(MAX_NODES);
        }

        // Build from existing array
        void build(vector<ll> &a)
        {
            roots.push_back(build(a, 0, size));
        }

        int build(vector<ll> &a, int lx, int rx)
        {
            int id = new_node(NEUTRAL_ELEMENT);
            if (rx - lx == 1)
            {
                if (lx < (int)a.size())
                    tree[id].item = single(a[lx]);
                return id;
            }
            int m = (lx + rx) / 2;
            tree[id].left = build(a, lx, m);
            tree[id].right = build(a, m, rx);
            tree[id].item = merge(tree[tree[id].left].item, tree[tree[id].right].item);
            return id;
        }

        // Point Update
        void set(int i, ll v, int x)
        {
            roots.push_back(set(i, v, x, 0, size));
        }

        int set(int i, ll v, int x, int lx, int rx)
        {
            int id = copy_node(x);
            if (rx - lx == 1)
            {
                tree[id].item = single(v);
                return id;
            }
            int m = (lx + rx) / 2;
            if (i < m)
                tree[id].left = set(i, v, tree[x].left, lx, m);
            else
                tree[id].right = set(i, v, tree[x].right, m, rx);
            tree[id].item = merge(tree[tree[id].left].item, tree[tree[id].right].item);
            return id;
        }

        // Range Query
        segtype calc(int l, int r, int x)
        {
            return calc(l, r, x, 0, size);
        }

        segtype calc(int l, int r, int x, int lx, int rx)
        {
            if (lx >= r || rx <= l)
                return NEUTRAL_ELEMENT;
            if (lx >= l && rx <= r)
                return tree[x].item;
            int m = (lx + rx) / 2;
            segtype s1 = calc(l, r, tree[x].left, lx, m);
            segtype s2 = calc(l, r, tree[x].right, m, rx);
            return merge(s1, s2);
        }
    };
} // namespace pers_seg

// SPARSE TABLE
namespace spa_table
{
    typedef ll spatype;
    struct SpaTable
    {
        vector<vector<spatype>> table;
        ll N, K;

        spatype merge(spatype a, spatype b)
        {
            return a + b;
        }

        SpaTable(ll n)
        {
            K = log2_floor(n);
            N = n;
            table = vector<vector<spatype>>(K + 1, vector<spatype>(n));
        }

        void build(vector<ll> arr)
        {
            table[0] = arr;
            for (int i = 1; i <= K; i++)
                for (int j = 0; j + (1 << i) <= N; j++)
                    table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }

        ll calc(int l, int r)
        {
            ll sum = 0;
            for (int i = K; i >= 0; i--)
            {
                if ((1 << i) <= r - l + 1)
                {
                    sum += table[i][l];
                    l += (1 << i);
                }
            }
            return sum;
        }

        ll calc_rmq(int l, int r)
        {
            int i = log2_floor(r - l + 1);
            return merge(table[i][l], table[i][r - (1 << i) + 1]);
        }

        int log2_floor(unsigned long i)
        {
            // return std::bit_width(i) - 1;
            // for pre C++20
            return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
        }
    };
} // namespace spa_table

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    cout << n * n << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
