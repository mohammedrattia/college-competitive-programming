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

const ll MOD = 1e9 + 7;
const int SZ = 1e6;
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

int arr[200005][32] = {0};
int pre[200005][32] = {0};

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0, cnt;
    rep(j, 0, 32)
    {
        ans = max(ans, pre[r][j] - pre[l - 1][j]);
    }
    cout << r - l + 1 - ans << endl;
}

int main()
{
    FAST;
    rep(i, 1, 200002)
    {
        int carry = 1;
        rep(j, 0, 32)
        {
            arr[i][j] = arr[i - 1][j] ^ carry;
            carry = arr[i - 1][j] & carry;
        }
    }
    rep(i, 1, 200002)
    {
        rep(j, 0, 32)
        {
            pre[i][j] = pre[i - 1][j] + arr[i][j];
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}