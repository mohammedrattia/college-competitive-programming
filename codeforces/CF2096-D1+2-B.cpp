#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<long long, long long>a, pair<long long, long long>b)
{
    return min(a.first, a.second) < min(b.first, b.second);
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    pair<long long, long long> arr[n];
    long long sumr = 0, suml = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        sumr += arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
        suml += arr[i].second;
    }
    sort(arr, arr+n, cmp);
    long long ans = suml + sumr;
    for (int i = 0; i < n-k+1; i++)
    {
        ans -= min(arr[i].first, arr[i].second);
        if (i == n-k) ans++;
    }
    cout << ans << '\n';
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