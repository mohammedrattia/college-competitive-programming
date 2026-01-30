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

ll nChoose3(ll n)
{
    if (n < 1)
        return 0;
    return n * (n + 1) * (n + 2) / 6;
}

void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int l = 0, r = 0;
    ll ans = 0;
    while (r < n)
    {
        if (arr[r] - arr[l] > 2)
        {
            ans += nChoose3(r - l - 2);
            while (arr[r] - arr[l] > 2)
            {
                l++;
            }
            ans -= nChoose3(r - l - 2);
        }
        r++;
    }
    ans += nChoose3(r - l - 2);
    cout << ans << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}