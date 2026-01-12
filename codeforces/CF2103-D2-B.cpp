#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pair<long long, long long> pr
// #define endl '\n'

void solve()
{
    int n;
    cin >> n;
    string str;
    int o = 0, z = 0, x = 0, zo = 0, oz = 0;
    cin >> str;
    o += str[0] == '1';
    z += str[0] == '0';
    rep(i, 1, n)
    {
        o += str[i] == '1';
        z += str[i] == '0';
        x += str[i]!=str[i-1];
    }
    if (z == n) cout << z << endl;
    else if (o == n) cout << o+1 << endl;
    else if (x==1 || x==2) cout << o+z+1 << endl;
    else cout << o+z+x-2+(str[0]=='1') << endl;
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