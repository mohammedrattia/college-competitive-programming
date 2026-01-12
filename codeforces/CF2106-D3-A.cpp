#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pair<long long, long long> pr
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll o = 0, z = 0;
    rep(i, 0, n)
    {
        o += str[i]=='1';
        z += str[i]=='0';
    }
    cout << o*n-o+z << endl;
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