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
    ll n, s;
    cin >> n >> s;
    ll num = n;
    stack<int> st;
    int sum = 0;
    while (num)
    {
        st.push(num % 10);
        sum += num % 10;
        num /= 10;
    }
    int sz = st.size();
    while (!st.empty() && (s - st.top() > 0 || (s - st.top() == 0 && sum - st.top() == 0)))
    {
        s -= st.top();
        sum -= st.top();
        st.pop();
        sz--;
    }
    if (st.empty())
    {
        cout << 0 << endl;
        return;
    }
    stack<int> digits;
    while (st.size() > 1)
    {
        digits.push(9 - st.top());
        st.pop();
    }
    digits.push(10 - st.top());
    string str = "";
    int val;
    while (!digits.empty())
    {
        val = digits.top();
        digits.pop();
        str = (char)(val % 10 + '0') + str;
        if (!digits.empty())
            digits.top() += val / 10;
    }
    if (val == 10)
        str = (char)(val / 10 + '0') + str;
    cout << stoll(str) << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
