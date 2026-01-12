#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pair<long long, long long> pr
#define endl '\n'

int solve()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n+5], s[n+5] = {0};
    ll mn = 1e9+10, posmn = 1e9+10, mx = -1e9;
    rep(i, 0, n)
    {
        cin >> arr[i];
        s[i+1] = s[i];
        if (arr[i]<=k)
            s[i+1]++;
        else s[i+1]--;
    }
    for (int r = 2; r < n; r++)
    {
        mn = min(mn, s[r-1]);
        mx = max(mx, s[r-1]);
        if(s[r-1]>=0) posmn=min(posmn, s[r-1]);
        if(s[r]<=s[n])
        {
            if (mx >= 0 || mn <= s[r]) return 1;
        }
        else if (posmn <= s[r]) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "Yes\n" : "No\n");
}