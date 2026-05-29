// #pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <iomanip>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

// BASIC DEFINES
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

// OTHER DEFINES
#define PI 3.14159265358979323846
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)
#define dbg(x) cout << #x << " = " << x << '\n'
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    string str;
    cin >> str;
    ll n = str.size();
    map<char, int> freq;
    rep(i, 0, n)
    {
        freq[str[i]]++;
    }
    priority_queue<pair<ll, char>, vector<pair<ll, char>>> pq;
    for (auto e : freq)
    {
        pq.push({e.S, e.F});
    }
    if (pq.top().F > n / 2 + n % 2)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    while (!pq.empty())
    {
        pair<ll, char> a = pq.top();
        pq.pop();
        cout << a.S;
        a.F--;
        if (!pq.empty())
        {
            pair<ll, char> b = pq.top();
            pq.pop();
            b.F--;
            cout << b.S;
            if (b.F != 0)
                pq.push(b);
        }
        if (a.F != 0)
            pq.push(a);
    }
    cout << endl;
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}
