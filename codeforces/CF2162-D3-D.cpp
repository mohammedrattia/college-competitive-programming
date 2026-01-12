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
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

void solve()
{
    int n;
    cin >> n;

    cout << "2 1 " << n << endl;
    cout.flush();
    int len;
    cin >> len;
    len -= n * (n + 1) / 2;
    vi arr;

    int l = 1, r = n;
    while (l + 1 < r)
    {
        int mid = l + (r - l + 1) / 2;
        arr.push_back(mid);

        int p, a;
        cout << "1 " << l << ' ' << mid << endl;
        cout.flush();
        cin >> p;
        cout << "2 " << l << ' ' << mid << endl;
        cout.flush();
        cin >> a;
        int diff = a - p;
        if (diff == len)
        {
            r = mid;
        }
        else if (diff == 0)
        {
            l = mid + 1;
        }
        else
        {
            cout << "! " << mid - diff + 1 << ' ' << mid + (len - diff) << endl;
            cout.flush();
            return;
        }
    }
    int p, a;
    if (len == 2)
    {
        cout << "! " << l << ' ' << r << endl;
        cout.flush();
        return;
    }

    cout << "1 " << l << ' ' << l << endl;
    cout.flush();
    cin >> p;
    cout << "2 " << l << ' ' << l << endl;
    cout.flush();
    cin >> a;
    if (p != a)
    {
        cout << "! " << l << ' ' << l << endl;
        cout.flush();
        return;
    }

    cout << "1 " << r << ' ' << r << endl;
    cout.flush();
    cin >> p;
    cout << "2 " << r << ' ' << r << endl;
    cout.flush();
    cin >> a;
    if (p != a)
    {
        cout << "! " << r << ' ' << r << endl;
        cout.flush();
        return;
    }
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
