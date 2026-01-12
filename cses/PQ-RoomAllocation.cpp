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
    ll n;
    cin >> n;
    pair<pii, int> arr[n];
    int a, b;
    rep(i, 0, n)
    {
        cin >> a >> b;
        arr[i] = {{a, b}, i};
    }
    sort(arr, arr + n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    int k = 1;
    int ans[n] = {0};
    rep(i, 0, n)
    {
        pair<int, int> c = q.top();
        if (arr[i].F.F > c.F)
        {
            q.pop();
            q.push({arr[i].F.S, c.S});
            ans[arr[i].S] = c.S;
        }
        else
        {
            q.push({arr[i].F.S, ++k});
            ans[arr[i].S] = k;
        }
    }
    cout << k << endl;
    rep(i, 0, n) cout << ans[i] << ' ';
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}