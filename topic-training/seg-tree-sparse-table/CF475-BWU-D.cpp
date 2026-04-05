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
        return gcd(a, b);
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
    ll n, m;
    cin >> n;

    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    arr.push_back(0);
    SpaTable st = SpaTable(n);
    st.build(arr);

    map<ll, ll> mp;

    rep(i, 0, n)
    {
        ll x = st.calc_rmq(i, i);
        int last = i;
        while (x)
        {
            int l = last, r = n;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                ll k = st.calc_rmq(i, mid);
                if (k < x)
                    r = mid;
                else
                    l = mid + 1;
            }
            mp[x] += l - last;
            x = st.calc_rmq(i, l);
            last = l;
            if (l == n)
                break;
        }
    }
    cin >> m;
    rep(i, 0, m)
    {
        ll c;
        cin >> c;
        cout << mp[c] << endl;
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
