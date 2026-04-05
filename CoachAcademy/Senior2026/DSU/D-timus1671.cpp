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

vll parent;
vll sizes;

void make_set(ll v)
{
    parent[v] = v;
    sizes[v] = 1;
}

ll find_set(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

void init_set(ll n)
{
    parent = vll(n);
    sizes = vll(n);
    rep(i, 0, n)
        make_set(i);
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m, q;
    cin >> n >> m;
    init_set(n);

    vector<pll> arr(m);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        arr[i] = {u, v};
    }

    cin >> q;
    vll idx(m, 1);
    stack<ll> tear;
    rep(i, 0, q)
    {
        ll a;
        cin >> a;
        a--;
        tear.push(a);
        idx[a] = 0;
    }

    ll k = n;
    rep(i, 0, m)
    {
        if (idx[i] && find_set(arr[i].F) != find_set(arr[i].S))
        {
            union_sets(arr[i].F, arr[i].S);
            k--;
        }
    }

    stack<ll> ans;
    while (!tear.empty())
    {
        pll cur = arr[tear.top()];
        tear.pop();
        ll u = cur.F, v = cur.S;

        ans.push(k);

        if (find_set(u) != find_set(v))
        {
            union_sets(u, v);
            k--;
        }
    }

    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
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
