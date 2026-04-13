#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

struct comp {
    constexpr bool operator()(
        pair<ll, ll> const& a,
        pair<ll, ll> const& b)
        const noexcept
    {
        return a.first < b.first;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, comp> jokey;
    ll v[n], d[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (ll i = 0; i < n; i++)
    {
        jokey.push({v[i], d[i]});
    }
    ll sum = 0;
    for (ll i = 0; i < m && !jokey.empty(); i++)
    {
        sum += jokey.top().first;
        if (jokey.top().first-jokey.top().second > 0)
            jokey.push({jokey.top().first-jokey.top().second, jokey.top().second});
        jokey.pop();
    }
    cout << sum << endl;
}
