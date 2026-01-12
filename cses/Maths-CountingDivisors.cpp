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
#define endl '\n'

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

vi p(SZ + 5, 1);
vi primes;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            cnt += 2;
        if (i * i == n)
            cnt--;
    }
    cout << cnt << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}