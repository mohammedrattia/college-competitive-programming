#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else return (a.second > b.second);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);
        arr.reserve(n);
        ll x, y;
        for (ll i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr[i] = {x, y};
        }
        sort(arr.begin(), arr.end(), comp);
        ll cur = arr[0].first, k = 0, pnts = 0;
        for (ll i = 0; i < n; i++)
        {
            cur = arr[i].first;
            if (k < cur)
            {
                pnts += arr[i].second;
                k++;
                if (k == cur || arr[i+1].first != cur)
                {
                    k = 0;
                    while (arr[i+1].first == cur)
                    {
                        i++;
                    }
                }
            }
        }
        cout << pnts << endl;
    }
}
