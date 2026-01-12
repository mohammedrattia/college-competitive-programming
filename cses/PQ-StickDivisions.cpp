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

void solve()
{
    ll n, x;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    int a, b;
    rep(i, 0, n)
    {
        cin >> a;
        q.push(a);
    }
    ll ans = 0;
    while (true)
    {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        ans += a + b;
        if (q.empty())
        {
            break;
        }
        q.push(a + b);
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}