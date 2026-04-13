#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>

using namespace std;

typedef long long ll;

ll n, arr[105] = { 0 };
map<pair<string, ll>, ll> term;
string cnt = "0000000000";
//ll cnt[10] = { 0 };
vector<vector<ll>> digits(105);

void get_digits(int &i, ll x)
{
    if(x >= 10)
       get_digits(i, x / 10);

    digits[i].push_back(x % 10);
}

bool only_two(ll num)
{
    bool b = true;
    for (auto digit : digits[num])
    {
        cnt[digit] += 1;
        if (cnt[digit] > '2')
            b = false;
    }
    return b;
}

void undo(ll num)
{
    for (auto digit : digits[num])
    {
        cnt[digit] -= 1;
    }
}

ll dp(ll i = 0)
{
    if (i == n)
    {
        return 0;
    }

    if (term.count({cnt, i}))
    {
        return term[{cnt, i}];
    }

    ll &ret = term[{cnt, i}];

    if (only_two(i))
    {
        ret = max(ret, dp(i+1)+arr[i]);
    }
    undo(i);
    ret = max(ret, dp(i+1));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        term.clear();
        //memset(cnt, 0, sizeof(cnt));
        cnt = "0000000000";
        digits = vector<vector<ll>>(105);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            get_digits(i, arr[i]);
        }
        cout << dp() << endl;
    }
}
