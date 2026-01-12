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
    ll n;
    cin >> n;
    vector<vll> arr(n, vll(n, 0));
    string str[n];
    rep(i, 0, n) cin >> str[i];
    if (str[0][0] == '*' || str[n - 1][n - 1] == '*')
    {
        cout << 0 << endl;
        return;
    }
    arr[0][0] = 1;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (is_valid(i - 1, j, n, n) && str[i - 1][j] != '*')
                (arr[i][j] += arr[i - 1][j]) %= MOD;
            if (is_valid(i, j - 1, n, n) && str[i][j - 1] != '*')
                (arr[i][j] += arr[i][j - 1]) %= MOD;
        }
    }
    cout << arr[n - 1][n - 1] << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}