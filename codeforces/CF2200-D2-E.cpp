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
const int SZ = 1e5 + 5;

vll spf;
void sieve(ll n)
{
    spf = vll(n + 1, 1);
    spf[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j <= n; j += i)
            {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}

vector<vector<int>> getFactorization(vector<int> arr)
{
    // precalculating Smallest Prime Factor
    vector<vector<int>> ret;
    
    return ret;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    ll b = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (i)
            b += arr[i] >= arr[i-1];
    }
    if (b == n-1)
    {
        cout << "Bob" << endl;
        return;
    }

    vector<map<ll, ll>> primes;
    rep (i, 0, n)
    {
        map<ll, ll> Pfactors;
        int x = arr[i];
        while (x != 1)
        {
            Pfactors[spf[x]]++;
            x = x / spf[x];
        }
        primes.push_back(Pfactors);
    }

    rep(i, 0, n)
    {
        if (primes[i].size() > 1)
        {
            cout << "Alice" << endl;
            return;
        }
    }

    vll p;
    b = 0;
    ll last = -1;
    rep(i, 1, n)
    {
        for(auto e:primes[i])
        {
            if (i)
                b += (e.F < last);
            last = e.F;
        }
    }
    if (b)
    {
        cout << "Alice" << endl;
        return;
    }
    else
    {
        cout << "Bob" << endl;
        return;
    }
}

int main()
{
    // FAST;
    sieve(SZ);
    int t;
    cin >> t;
    while (t--)
        solve();
}
