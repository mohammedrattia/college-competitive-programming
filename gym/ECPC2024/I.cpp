#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && j < m; }
ll dy[4]{1, 0, -1, 0}, dx[4]{0, -1, 0, 1};

bool isPal(const string &str, ll l, ll r)
{
    while (l < r)
    {
        if (str[l] != str[r])
            return 0;
        l++, r--;
    }
    return 1;
}
void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll l = 0, r = 0, sum = 0, res = INT_MIN;
    while (r < n)
    {
        if ((sum + arr[r]) == (sum | arr[r]))
        {
            sum += arr[r];
            ll x = l;
            while (x <= r)
            {
                if (isPal(str, x, r))
                    res = max(res, r - x + 1);
                x++;
            }
            r++;
        }
        else
        {
            sum -= arr[l];
            l++;
        }
    }
    cout << res << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}

/*
1
5
aabaa
1 2 5 2 1
*/