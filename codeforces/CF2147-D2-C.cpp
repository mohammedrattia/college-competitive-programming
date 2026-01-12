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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = "WW" + s + "WW";
    string t(s);
    rep(i, 2, n + 2)
    {
        if (s[i] == '0')
        {
            int l = 0, r = 0;
            if (s[i - 1] == 'W' || s[i - 1] == '0' || (s[i - 1] == '1' && s[i - 2] == '0'))
                l = 1;
            if (s[i + 1] == 'W' || s[i + 1] == '0' || (s[i + 1] == '1' && s[i + 2] == '0'))
                r = 1;
            if (l && r)
                t[i] = '?';
            else if (l)
                t[i] = 'L';
            else if (r)
                t[i] = 'R';
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    rep(i, 2, n + 2)
    {
        if (t[i] == 'R')
        {
            if (t[i + 1] == '1' && t[i + 2] == '?')
                t[i + 2] = 'L';
            if (t[i + 1] == '1' && t[i + 2] != 'L')
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (t[i] == 'L')
        {
            if (t[i - 1] == '1' && t[i - 2] == '?')
                t[i - 2] = 'R';
            if (t[i - 1] == '1' && t[i - 2] != 'R')
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (t[i] == '?')
        {
            int l = 0, r = 0;
            if ((t[i - 1] == '1' && t[i - 2] == 'R') || (t[i + 1] == '1' && t[i + 2] == 'R'))
                l = 1;
            if ((t[i + 1] == '1' && t[i + 2] == 'L') || (t[i - 1] == '1' && t[i - 2] == 'L'))
                r = 1;
            if (l && r)
            {
                cout << "NO" << endl;
                return;
            }
            else if (l)
                t[i] = 'L';
            else if (r)
                t[i] = 'R';
        }
    }
    rrep(i, n + 2, 2)
    {
        if (t[i] == 'R')
        {
            if (t[i + 1] == '1' && t[i + 2] == '?')
                t[i + 2] = 'L';
            if (t[i + 1] == '1' && t[i + 2] != 'L')
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (t[i] == 'L')
        {
            if (t[i - 1] == '1' && t[i - 2] == '?')
                t[i - 2] = 'R';
            if (t[i - 1] == '1' && t[i - 2] != 'R')
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (t[i] == '?')
        {
            int l = 0, r = 0;
            if (t[i - 1] == '1' && t[i - 2] == 'R')
                l = 1;
            if (t[i + 1] == '1' && t[i + 2] == 'L')
                r = 1;
            if (l && r)
            {
                cout << "NO" << endl;
                return;
            }
            else if (l)
                t[i] = 'L';
            else if (r)
                t[i] = 'R';
        }
    }
    cout << "YES" << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
