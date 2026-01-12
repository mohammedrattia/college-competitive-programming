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
    vector<pii> arr(n);
    rep(i, 0, n)
    {
        int a;
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr.begin(), arr.end());
    rep(i, 0, n)
    {
        arr[i].S = abs(arr[i].S - i);
    }
    int last = 0;
    stack<int> s;
    rep(i, 0, n)
    {
        if (last == arr[i].F)
        {
            if (!s.empty() && arr[i].S % 2 == s.top() % 2)
                s.pop();
            else
                s.push(arr[i].S);
        }
        else
        {
            if ((s.size() == 1 && s.top() % 2 == 1) || s.size() > 1)
            {
                cout << "NO" << endl;
                return;
            }
            while (!s.empty())
            {
                s.pop();
            }
            s.push(arr[i].S);
        }
        last = arr[i].F;
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
