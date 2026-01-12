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

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

vll arr;
void solve()
{
    ll n;
    cin >> n;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    ll p = 1;
    rep(i, 0, 63)
    {
        arr.PB(p);
        p = (p << 1) + 1;
    }
    while (t--)
        solve();
}