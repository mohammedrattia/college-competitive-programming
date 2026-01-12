#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

void solve()
{
    int n;
    cin >> n;
    long long arr[n];
    map<long long, long long> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long l = 0, r = 0, cnt = 0;
    while (r != n)
    {
        if (mp[arr[r]])
        {
            cnt += (r - l) * (r - l + 1) / 2;
            while (arr[l] != arr[r])
            {
                mp[arr[l++]]--;
            }
            mp[arr[l++]]--;
            cnt -= (r - l) * (r - l + 1) / 2;
        }
        mp[arr[r++]]++;
    }
    cnt += (r - l) * (r - l + 1) / 2;
    cout << cnt << '\n';
}
// 1 2 3 4 3 2 1

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
