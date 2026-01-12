#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> div;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (i != n / i)
                div.push_back(n / i);
        }
    }

    if (k > div.size())
    {
        cout << -1;
        return 0;
    }
    sort(div.begin(), div.end());
    cout << div[k - 1];
}
