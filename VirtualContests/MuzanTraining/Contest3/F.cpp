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

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n'
#define endl '\n'

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

vll parent;
vector<ll> black;
vector<ll> color;
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
    {
        parent[b] = a;
        black[a] += black[b];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    parent = vll(n);
    black = vector<ll>(n, 0);
    color = vector<ll>(n, 0);
    rep(i, 0, n)
    {
        parent[i] = i;
    }
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int a, b;
            cin >> a >> b;
            union_sets(a - 1, b - 1);
        }
        else if (c == 2)
        {
            int a, b;
            cin >> a;
            b = find_set(a - 1);
            if (color[a - 1])
            {
                black[b]--;
                color[a - 1] = 0;
            }
            else
            {
                black[b]++;
                color[a - 1] = 1;
            }
        }
        else
        {
            int a, b;
            cin >> a;
            b = find_set(a - 1);
            if (black[b])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
