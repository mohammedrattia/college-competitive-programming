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

void solve()
{
    int n, k;
    cin >> n >> k;
    ll a, colors[n] = {0};
    priority_queue<pll, vector<pll>> pq;
    int freq[n + 1] = {0};
    rep(i, 0, n)
    {
        cin >> a;
        if (freq[a] < k)
            pq.push({a, i});
        freq[a]++;
    }
    ll last = -1, c = 0, last_color = 0;
    while (!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        if (cur.F != last)
        {
            last = cur.F;
            last_color = c;
        }
        else if (c == last_color)
        {
            while (cur.F == last && !pq.empty())
            {
                cur = pq.top();
                pq.pop();
            }
            if (pq.empty() && cur.F == last)
            {
                break;
            }
            pq.push(cur);
            continue;
        }
        colors[cur.S] = c + 1;
        c++;
        c %= k;
        if (pq.size() < k && c == 0)
        {
            break;
        }
    }
    rep(i, 0, n)
    {
        cout << colors[i] << ' ';
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
