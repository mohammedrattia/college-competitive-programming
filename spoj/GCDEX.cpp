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

ll phi[SZ + 1];
ll ans[SZ + 1];

int main()
{
    FAST;
    rep(i, 1, SZ + 1) phi[i] = i;
    rep(i, 2, SZ + 1)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= SZ; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    rep(i, 1, SZ + 1)
    {
        for (ll j = i + i; j <= SZ; j += i)
        {
            ans[j] += phi[j / i] * i;
        }
    }
    rep(i, 1, SZ + 1)
    {
        ans[i] += ans[i - 1];
    }
    ll n;
    cin >> n;
    while (n)
    {
        cout << ans[n] << endl;
        cin >> n;
    }
}