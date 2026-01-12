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
const int SZ = 200;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

vll is_prime;
vll primes;
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    ll val = 1, cur = 1, ans = 0;
    for (ll e = 2; e < 100; e++)
    {
        ans += (n / cur - n / lcm(cur, e)) * e;
        cur = lcm(cur, e);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    // FAST;
    is_prime = vll(SZ, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i <= SZ; i++)
    {
        for (int j = i * 2; j <= SZ; j += i)
        {
            if (is_prime[j] == 1)
                is_prime[j] = 0;
        }
    }
    rep(i, 0, SZ)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}
