#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

vector<ll> arr;
ll n, x;

ll rides()
{
    int p = 0;
    int s = 0, cnt = 0;

    while (p < n)
    {
        if (s + arr[p] <= x)
        {
            s += arr[p];
        }
        else
        {
            s = arr[p];
            cnt++;
        }
        p++;
    }
    if (s > 0)
        cnt++;
    return cnt;
}

ll permute(int idx = 0)
{
    if (idx == n)
        return INF;

    ll ret = rides();

    for (int i = idx + 1; i < n; i++)
    {
        swap(arr[idx], arr[i]);
        ret = min(ret, permute(idx + 1));
        swap(arr[idx], arr[i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    arr = vector<ll>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << permute() << endl;
}
