#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
#define F first
#define S second
#define pr pair<long long, long long>
// #define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    string str;
    ll arr[26] = { 0 };
    ll last[26] = { 0 };
    cin >> str;
    int pre = str[0]-'a';
    int cnt = 1;
    rep(i, 1, n)
    {
        if (str[i]==str[i-1])
        {
            cnt++;
        }
        else break;
    }
    if (cnt == n)
    {
        cout << cnt << endl;
        return;
    }
    rep(i, cnt, n+1)
    {
        if (str[i]!=str[i-1])
        {
            int idx = str[i-1]-'a';
            arr[idx] = max(arr[idx], last[idx]);
            last[idx] = 0;
            if (i == n) break;
        }
        last[str[i]-'a']++;
    }
    ll mx = cnt + arr[pre];
    rep(i, 0, 26)
    {
        mx = max(mx, arr[i]);
    }
    cout << mx << endl;
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

