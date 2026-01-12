#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <cmath>
#include <array>
#include <queue>
#include <stack>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pii pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        cout << "Luxor" << endl;
    else if (n < m)
        cout << "Sharm El-shaikh" << endl;
    else
        cout << "impossible" << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}