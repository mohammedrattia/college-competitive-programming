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
    int n;
    cin >> n;
    map<ll, ll> mp;
    int a;
    rep(i, 0, n)
    {
        cin >> a;
        mp[a]++;
    }
    priority_queue<pll, vector<pll>> pq;
    for (auto e : mp)
    {
        pq.push({e.S, e.F});
    }
    pll l, s;
    ll ans = 0;
    while (!pq.empty())
    {
        l = pq.top();
        pq.pop();
        if (pq.empty())
        {
            ans = l.F;
            break;
        }
        s = pq.top();
        pq.pop();
        l.F--;
        s.F--;
        if (l.F)
            pq.push(l);
        if (s.F)
            pq.push(s);
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}