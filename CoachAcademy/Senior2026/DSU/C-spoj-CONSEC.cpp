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

void union_sets(ll &a, ll &b)
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
void solve(int t)
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    string str;
    cin >> str;
    n = str.size();
    string c = str;
    cin >> q;
    init_set(n);

    ll k = n, mx = 1ll;
    stack<pll> arr;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        arr.push({u, v});
        if (u == 2)
        {
            c[v] = '#';
        }
    }

    rep(i, 1, n)
    {
        if (c[i] == c[i - 1] && c[i] != '#')
        {
            ll v = i - 1ll, x = i;
            union_sets(x, v);
        }
    }

    stack<ll> ans;
    while (!arr.empty())
    {
        pll cur = arr.top();
        arr.pop();
        ll u = cur.F, v = cur.S;

        if (u == 1)
            ans.push(sizes[find_set(v)]);
        else
        {
            c[v] = str[v];
            if (v != n - 1 && c[v] == c[v + 1])
            {
                ll i = v + 1ll, x = v;
                union_sets(i, x);
            }
            if (v != 0 && c[v] == c[v - 1])
            {
                ll i = v - 1ll, x = v;
                union_sets(i, x);
            }
        }
    }

    cout << "Case " << t << ":" << endl;
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}
