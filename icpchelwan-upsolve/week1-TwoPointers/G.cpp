#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

void solve()
{
    int n, x;
    cin >> n >> x;
    long long arr[n];
    map<long long, long long> mp;
    long long pre[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i - 1];
    }

    long long cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        cnt += mp[pre[i] - x];
        mp[pre[i]]++;
    }

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
