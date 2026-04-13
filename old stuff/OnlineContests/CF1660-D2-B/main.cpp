#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define rep(i, n) for (long long i = 0; i < n; i++)

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep (i, n)
            cin >> a[i];

        if (n == 1)
        {
            if (a[0] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        sort(a.begin(), a.end());

        if (a[n-1] - a[n-2] <= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
