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

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

void solve()
{
    ll n;
    string str;
    cin >> n >> str;
    ll arr[n];
    vll idx[127];
    ll freq[127] = {0};
    vll ans(n, 1);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n)
    {
        idx[str[i]].PB(i);
        freq[str[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        bool x = 0;
        ll cnt = 0;
        for (auto &e : idx[i])
        {
            if (freq[i] == 1)
                break;
            if (x || str[e + 1] < str[e])
            {
                ll j = e;
                if (cnt + 1 < freq[i])
                {
                    while (j >= 0 && str[j] == str[e])
                    {
                        ans[e] = 0;
                        freq[i]--;
                        j--;
                    }
                }
                cnt = 0;
            }
            else if (str[e + 1] > str[e])
            {
                x = 1;
            }
            else
                cnt++;
        }
    }
    rep(i, 0, n - 1)
    {
        if (ans[i] && ans[i + 1] && str[i] == str[i + 1])
        {
            ll mx = arr[i], x = i;
            while (ans[i + 1] && str[i + 1] == str[x])
            {
                if (arr[i + 1] > mx)
                {
                    ans[x] = 0;
                    mx = arr[i + 1];
                    x = i + 1;
                }
                else
                {
                    arr[i + 1] = 0;
                }
                i++;
            }
        }
    }
    ll sum = 0;
    rep(i, 0, n)
    {
        if (ans[i])
        {
            cout << str[i];
            sum += arr[i];
        }
    }
    cout << endl;
    cout << sum << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}