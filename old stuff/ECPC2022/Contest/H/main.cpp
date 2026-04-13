#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int arr[55];

int main()
{
    freopen("grid.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));

    int a;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a;
            arr[i]+=a;
        }
    }
    if (m&2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    bool b = 0;
    rep(i, n)
    {
        int mx = min(arr[i] + 1, m), mn = max(arr[i] - 1, 0);
        if (m/2 != mx && m/2 != mn && m/2 != arr[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
