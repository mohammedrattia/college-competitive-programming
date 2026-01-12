#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && j < m; }
ll dy[4]{1, 0, -1, 0}, dx[4]{0, -1, 0, 1};

class DisjointSets
{
public:
    vector<int> parents;
    vector<int> sizes;
    DisjointSets(int size) : parents(size), sizes(size, 1)
    {
        for (int i = 0; i < size; i++)
        {
            parents[i] = i;
        }
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    int unite(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root)
        {
            return -1;
        }

        if (sizes[x_root] < sizes[y_root])
        {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return sizes[x_root];
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    DisjointSets dsu(n);
    int cnt = n, mx = 0;

    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int size = dsu.unite(a, b);
        if (size != -1)
            cnt--;
        mx = max(size, mx);
        cout << cnt << ' ';
        cout << mx << endl;
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