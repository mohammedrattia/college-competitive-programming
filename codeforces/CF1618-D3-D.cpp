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
#define pi pair<int, int>
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

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll arr(n);
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll score = 0;
    sort(arr.begin(), arr.end());
    rrep(i, n - 1, n - k)
    {
        score += arr[i - k] / arr[i];
        sum -= arr[i] + arr[i - k];
    }
    cout << score + sum << endl;
}

int main()
{
    FAST int t;
    cin >> t;
    while (t--)
        solve();
}