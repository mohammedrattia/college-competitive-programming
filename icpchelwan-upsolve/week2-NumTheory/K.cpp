#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int gcd = arr[0];
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, arr[i]);
    }
    cout << mx / gcd << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
