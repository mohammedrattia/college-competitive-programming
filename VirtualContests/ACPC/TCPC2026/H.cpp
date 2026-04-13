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
void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

void init_set(ll n)
{
    parent = vll(n);
    rep(i, 0, n)
    {
        parent[i] = i;
    }
}

bool comp(array<ll, 3> a, array<ll, 3> b)
{
    return a[1] > b[1];
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m, q;
    cin >> n >> m >> q;
    init_set(n);
    vector<array<ll, 3>> e(m);
    rep(i, 0, m)
    {
        cin >> e[i][1] >> e[i][2];
        e[i][0] = e[i][1] + e[i][2];
        e[i][1]--, e[i][2]--;
    }
    sort(all(e), greater<>());
    vector<array<ll, 3>> queries(q);
    rep(i, 0, q)
    {
        queries[i][0] = i;
        cin >> queries[i][1];
    }
    sort(all(queries), comp);

    ll k = 0, val = n;
    rep(i, 0, q)
    {
        if (k < m) while (e[k][0] > queries[i][1])
        {
            if (find_set(e[k][1]) != find_set(e[k][2]))
            {
                union_sets(e[k][1], e[k][2]);
                val--;
            }
            k++;
            if (k == m) break;
        }
        queries[i][2] = val;
    }
    sort(all(queries));
    rep(i, 0, q) cout << queries[i][2] << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
