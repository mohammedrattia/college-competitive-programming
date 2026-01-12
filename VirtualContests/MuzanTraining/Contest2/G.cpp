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

int n, k, val, rem, c;
vi ans;

void rec(int i, int j, int cnt)
{
    if (i + 1 == j)
    {
        if (cnt > 0)
            ans[i]++;
        else if (cnt > 1)
            ans[j]++;
        return;
    }
    rec(i, i + (j - i) / 2, cnt / 2);
    rec(i + (j - i) / 2, j, cnt / 2 + cnt % 2);
}

void solve()
{
    cin >> n >> k;
    c = pow(2, n);
    val = k / c;
    rem = k % c;
    ans = vi(c, val);
    if (rem == 0)
    {
        cout << 0 << endl;
        rep(i, 0, c) cout << ans[i] << ' ';
    }
    else
    {
        cout << 1 << endl;
        rec(0, c - 1, rem);
        rep(i, 0, c) cout << ans[i] << ' ';
    }
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
