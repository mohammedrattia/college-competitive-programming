#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    map<int, int> mp;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto e : mp)
    {
        s.insert(e.second);
    }
    for (int i = 0; i < q; i++)
    {
        int x, r;
        cin >> x >> r;
        x--;
        if (arr[x] != r)
        {
            auto it = s.find(mp[arr[x]]);
            s.erase(it);
            if (mp[r] > 0)
            {
                it = s.find(mp[r]);
                s.erase(it);
            }

            mp[arr[x]]--;
            s.insert(mp[arr[x]]);
            mp[r]++;
            s.insert(mp[r]);

            arr[x] = r;
        }

        cout << *s.rbegin() << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}