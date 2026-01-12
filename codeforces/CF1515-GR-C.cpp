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

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    ll a, ans[n];
    priority_queue<pll, vector<pll>> pq;
    priority_queue<pll, vector<pll>, greater<>> sum;
    vector<vll> arr(m);
    rep(i, 0, n)
    {
        cin >> a;
        pq.push({a, i});
        if (i < m)
            sum.push({0, i});
    }
    ll last = 1;
    while (!pq.empty())
    {
        pll cur = sum.top();
        sum.pop();

        arr[cur.S].push_back(pq.top().S);
        sum.push({cur.F + pq.top().F, cur.S});
        pq.pop();
    }
    vector<ll> comp(m);
    rep(i, 0, m)
    {
        comp[i] = sum.top().F;
        sum.pop();
    }
    if (comp[0] - comp[m - 1] > x)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "Yes" << endl;
    }
    rep(i, 0, m)
    {
        for (auto e : arr[i])
        {
            ans[e] = i + 1;
        }
    }
    rep(i, 0, n)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
