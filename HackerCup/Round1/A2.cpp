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
#define answer(x) cout << "Case #" << T - t << ": " << x

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

vll arr;
vll sol;
int T;
void solve(int t)
{
    ll n;
    cin >> n;
    arr = vll(n);
    vll freq(n, 0);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    vector<pll> data;
    priority_queue<pll, vector<pll>> pq;
    ll k = 0;
    rep(i, 0, n)
    {
        pq.push({arr[i], k++});
        data.push_back({i, 0});
        if (i < n - 1)
        {
            pq.push({abs(arr[i] - arr[i + 1]), k++});
            data.push_back({i, 1});
        }
        else
        {
            pq.push({arr[i], k++});
            data.push_back({i, 0});
        }
    }
    vll ans;
    while (!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        pll d = data[cur.S];
        if (freq[d.F] == 2 || (freq[d.F + 1] == 2 && d.S == 1) || (ans.size() + pq.size() + 1 == n))
        {
            ans.push_back(cur.F);
        }
        else
        {
            freq[d.F]++;
            if (d.S == 1)
            {
                freq[d.F + 1]++;
            }
        }
    }
    ll val = *max_element(ans.begin(), ans.end());
    answer(val);
    cout << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    T = t;
    while (t--)
        solve(t);
}
