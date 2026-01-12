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

vector<vector<int>> vis;

int n, m;
vector<int> ans;

bool valid(int i, int j)
{
    return i < n && i >= 0 && j < m && j >= 0;
}

void solve()
{
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<pair<pii, int>> q;
    int dis = (n / 2) + (m / 2);
    vis[n / 2][m / 2] = 1;

    q.push({{n / 2, m / 2}, dis});
    if (n % 2 == 0)
    {
        vis[n / 2 - 1][m / 2] = 1;
        q.push({{n / 2 - 1, m / 2}, dis});
    }
    if (m % 2 == 0)
    {
        vis[n / 2][m / 2 - 1] = 1;
        q.push({{n / 2, m / 2 - 1}, dis});
    }
    if (n % 2 == 0 && m % 2 == 0)
    {
        vis[n / 2 - 1][m / 2 - 1] = 1;
        q.push({{n / 2 - 1, m / 2 - 1}, dis});
    }
    pair<pii, int> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        cout << cur.S << ' ';
        int i = cur.F.F, j = cur.F.S;
        if (valid(i + 1, j) && !vis[i + 1][j])
        {
            vis[i + 1][j] = 1;
            q.push({{i + 1, j}, cur.S + 1});
        }
        if (valid(i, j + 1) && !vis[i][j + 1])
        {
            vis[i][j + 1] = 1;
            q.push({{i, j + 1}, cur.S + 1});
        }
        if (valid(i - 1, j) && !vis[i - 1][j])
        {
            vis[i - 1][j] = 1;
            q.push({{i - 1, j}, cur.S + 1});
        }
        if (valid(i, j - 1) && !vis[i][j - 1])
        {
            vis[i][j - 1] = 1;
            q.push({{i, j - 1}, cur.S + 1});
        }
    }
    cout << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}