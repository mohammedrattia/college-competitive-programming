#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pr pair<long long, long long>
// #define endl '\n'

bool cmp(pr a, pr b)
{
    return a.F > b.F;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    pr arr[n];
    rep(i, 0, n)
    {
        cin >> arr[i].F;
        arr[i].S = i + 1;
    }
    sort(arr, arr + n);
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            ll rem = x - arr[i].F - arr[j].F;
            if (rem < 0)
                break;
            ll l = 0, r = n - 1, mid;
            while (l < r)
            {
                mid = l + (r - l) / 2;
                if (arr[mid].F > rem)
                    r = mid - 1;
                else if (arr[mid].F < rem)
                    l = mid + 1;
                else
                    break;
            }
            if (arr[mid].F == rem && arr[i].S != arr[j].S && arr[i].S != arr[mid].S && arr[j].S != arr[mid].S)
            {
                cout << arr[i].S << ' ' << arr[j].S << ' ' << arr[mid].S << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
