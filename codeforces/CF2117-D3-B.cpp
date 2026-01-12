#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
#define F first
#define S second
#define pr pair<long long, long long>
#define vl vector<long long>
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i += 2)
    {
        cout << i << ' ';
    }
    for (int i = n - (n % 2); i >= 1; i -= 2)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
