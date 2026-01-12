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
#include <random>

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
const ll llMOD = 1e9 + 7;
const ll iMOD = 998244353;
const ll MOD = 676767677;
const int SZ = 2 * 1e5 + 5;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    vll mx;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] == n)
            mx.push_back(i);
    }
    if (mx.size() > 2)
    {
        cout << 0 << endl;
        return;
    }
    vll dir(n, -1);
    int b = 1;
    rep(i, 1, n)
    {
        if (abs(arr[i] - arr[i - 1]) >= 2)
        {
            cout << 0 << endl;
            return;
        }
        if (arr[i] == arr[i - 1] + 1)
        {
            if (dir[i] == 0 || dir[i - 1] == 0)
            {
                cout << 0 << endl;
                return;
            }
            dir[i] = dir[i - 1] = 1;
            b = 0;
        }
        else if (arr[i] + 1 == arr[i - 1])
        {
            if (dir[i] == 1 || dir[i - 1] == 1)
            {
                cout << 0 << endl;
                return;
            }
            dir[i] = dir[i - 1] = 0;
            b = 0;
        }
        else if (arr[i] == arr[i - 1])
        {
            if (dir[i] != -1)
                dir[i - 1] = !dir[i];
            else if (dir[i - 1] != -1)
                dir[i] = !dir[i - 1];
        }
    }
    for (ll e : mx)
    {
        rep(i, e + 1, n)
        {
            if (dir[i] == 1)
            {
                cout << 0 << endl;
                return;
            }
        }
        rep(i, 0, e - 1)
        {
            if (dir[i] == 0)
            {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (b)
        cout << 2 << endl;
    else
        cout << 1 << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
