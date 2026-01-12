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
const int SZ = 2 * 1e5 + 5;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

void solve()
{
    ll n;
    cin >> n;
    vector<vll> adj(n);
    if (n % 2 == 0)
    {
        int cur = 0, last = 1;
        rep(i, 0, n)
        {
            int last = (i % 2 ? -1 : 1);
            rep(j, i + 1, n)
            {
                if (i == cur && j == cur + 1)
                {
                    adj[i].push_back(0);
                    adj[j].push_back(0);
                    cur += 2;
                }
                else
                {
                    adj[i].push_back(1 * last);
                    adj[j].push_back(-1 * last);
                    last = -last;
                }
            }
        }
    }
    else
    {
        rep(i, 0, n)
        {
            int last = 1;
            rep(j, i + 1, n)
            {

                adj[i].push_back(1 * last);
                adj[j].push_back(-1 * last);
                last = -last;
            }
        }
    }
    rep(i, 0, n - 1)
    {
        rep(j, i, n - 1)
        {
            cout << adj[i][j] << ' ';
        }
    }
    cout << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
