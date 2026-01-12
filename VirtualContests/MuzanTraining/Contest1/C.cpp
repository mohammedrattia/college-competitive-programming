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

vi visited;
vector<vll> adj;
int n, cnt = 0;

void dfs(int i)
{
    if (visited[i])
        return;
    visited[i] = 1;
    cnt++;
    for (auto e : adj[i])
    {
        dfs(e);
    }
}

void solve()
{
    cin >> n;
    visited = vi(n, 0);
    adj = vector<vll>(n);
    vll learned;

    rep(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 0)
            learned.push_back(i);
        else
        {
            adj[a - 1].push_back(i);
            adj[b - 1].push_back(i);
        }
    }
    for (auto e : learned)
    {
        if (!visited[e])
            dfs(e);
    }
    cout << cnt << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}