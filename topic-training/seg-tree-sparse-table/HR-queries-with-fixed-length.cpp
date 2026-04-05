// #pragma GCC optimize("O2")

#include <iostream>
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
#include <bitset>

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

// SPAESE TREE
typedef ll spatype;
struct SpaTable
{
    vector<vector<spatype>> table;
    ll N, K;

    spatype merge(spatype a, spatype b)
    {
        return max(a, b);
    }

    SpaTable(ll n)
    {
        K = log2_floor(n);
        N = n;
        table = vector<vector<spatype>>(K + 2, vector<spatype>(n + 1, 0));
    }

    void build(vector<ll> arr)
    {
        table[0] = arr;
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }

    ll calc(int l, int r)
    {
        ll sum = 0;
        for (int i = K; i >= 0; i--)
        {
            if ((1 << i) <= r - l + 1)
            {
                sum += table[i][l];
                l += (1 << i);
            }
        }
        return sum;
    }

    ll calc_rmq(int l, int r)
    {
        int i = log2_floor(r - l + 1);
        return merge(table[i][l], table[i][r - (1 << i) + 1]);
    }

    int log2_floor(unsigned long i)
    {
        // return std::bit_width(i) - 1;
        // for pre C++20
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n >> q;

    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    SpaTable st = SpaTable(n);
    st.build(arr);

    ll mn = INF;

    rep(i, 0, q)
    {
        ll d;
        cin >> d;
        d--;
        rep(j, 0, n - d)
        {
            mn = min(mn, st.calc_rmq(j, j + d));
        }
        cout << mn << endl;
        mn = INF;
    }
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
