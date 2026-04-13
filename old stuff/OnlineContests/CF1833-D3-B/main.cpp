#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[n];
        int b[n];
        pair<int, int> mp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[i] = {i, a[i]};
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(b, b+n);
        sort(mp, mp+n, cmp);

        pair<int, int> ans[n];
        for (int i = 0; i < n; i++)
        {
            ans[i] = {b[i], mp[i].first};
        }
        sort(ans, ans+n, cmp);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i].first << ' ';
        }
        cout << endl;
    }
}
