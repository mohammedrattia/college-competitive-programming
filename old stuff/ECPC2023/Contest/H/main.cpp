#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        ll cnt = n;
        for (ll i = 0, j = n-1; i < n && j >= 0 && j > i;)
        {
            if (arr[i]+arr[j]+1 <= c)
            {
                cnt--;
                i++;
                j--;
            }
            else j--;
        }
        cout << cnt << endl;
    }
}
