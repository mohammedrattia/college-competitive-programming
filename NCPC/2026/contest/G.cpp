// #pragma GCC optimize("O2")

#include <iostream>
#include <iomanip>
#include <sstream>
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

// SOLVE SPACE
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
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    map<ll, char> p;
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        p[a] = '(';
    }
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        p[a] = ')';
    }
    queue<ll> q;
    stack<char> s;
    ll cnt = 0;
    ll ans = 1;
    for (auto [v, c] : p)
    {
        if (!s.empty() && c != s.top() && s.top() != '?')
        {
            if (c == '(')
            {
                cout << 0 << endl;
                return;
            }
            s.pop();
            cnt++;
        }
        else
        {
            if (!s.empty() && s.top() == '?')
            {
                q.push(cnt);
                cnt = 0;
                s.pop();
                if (!s.empty() && c != s.top() && s.top() != '?')
                {
                    s.pop();
                    cnt++;
                }
            }
            else if (!s.empty() && c == s.top() && cnt)
            {
                q.push(cnt);
                cnt = 0;
                s.push('?');
                s.push(c);
            }
            else if (s.empty())
            {
                q.push(cnt);
                cnt = 0;
                s.push(c);
            }
            else
                s.push(c);
        }
    }
    q.push(cnt);
    while (!q.empty())
    {
        ans *= fact[q.front()];
        ans %= MOD;
        q.pop();
    }
    cout << ans << endl;
}

int main()
{
    // FAST;
    preFact(1e6);
    int t;
    cin >> t;
    while (t--)
        solve();
}
