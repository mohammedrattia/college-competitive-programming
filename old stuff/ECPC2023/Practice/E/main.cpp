#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[(ll)n];
        double sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);

        ll even[n] = { 0 }, up[n] = { 0 }, down[n] = { 0 }, cost[n] = { 0 }, ans = 1000000000000000;
        ll cnt = 0;
        for (ll i = 1; i < n; i++)
        {
            cost[i] = cost[i-1];
            if (arr[i-1] % 2 == 0)
                cnt += 2;
            if (arr[i] > arr[i-1])
            {
                cost[i] += cnt;
                cnt = 0;
            }
        }

        cnt = 0;
        for (ll i = n-2; i >=0; i--)
        {
            even[i] = even[i+1];
            if (arr[i+1] % 2 != 0)
                cnt += 2;
            if (arr[i] < arr[i+1])
            {
                even[i] += cnt;
                cnt = 0;
            }
            cost[i] += even[i];
        }

        cnt = 0;
        for (ll i = 1; i < n; i++)
        {
            up[i] = up[i-1];
            up[i] += i*(arr[i]-arr[i-1]);
            cost[i] += up[i];
        }

        cnt = 0;
        for (ll i = n-2; i >=0; i--)
        {
            down[i] = down[i+1];
            down[i] += (n-i-1)*(arr[i+1]-arr[i]);
            cost[i] += down[i];
        }

        for (ll i = 0; i < n; i++)
        {
            ans = min(ans, cost[i]);
        }
        cout << ans << endl;
    }

}
