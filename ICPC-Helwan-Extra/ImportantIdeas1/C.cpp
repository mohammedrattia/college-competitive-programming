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
// #define endl '\n'

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

void solve()
{
    string str;
    cin >> str;
    ll n = sz(str);
    int freq[26] = {0};
    rep(i, 0, n)
    {
        freq[(int)(str[i] - 'a')]++;
        if (str[i] == 'h')
        {
            cout << "impossible";
            return;
        }
    }
    priority_queue<pii> pq;
    rep(i, 0, 26)
    {
        if (freq[i] > n / 2 + (n % 2))
        {
            cout << "impossible";
            return;
        }
        if (freq[i] != 0)
            pq.push({freq[i], i});
    }
    while (!pq.empty())
    {
        pii a = pq.top();
        pq.pop();
        cout << (char)('a' + a.S);

        if (pq.empty())
            break;

        pii b = pq.top();
        pq.pop();
        cout << (char)('a' + b.S);

        if (a.F > 1)
            pq.push({a.F - 1, a.S});
        if (b.F > 1)
            pq.push({b.F - 1, b.S});
    }
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}