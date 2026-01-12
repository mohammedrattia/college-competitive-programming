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
    ll arr[n];
    double sum = 0;
    rep(i, 0, n)
    {
        cin >> arr[n];
        sum += arr[i];
    }
    double y;
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
