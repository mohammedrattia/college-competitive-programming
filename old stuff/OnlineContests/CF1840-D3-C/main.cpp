#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, q, cnt = 0, x;
        cin >> n >> k >> q;
        long long arr[n];
        vector<int> subs;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x>q && cnt!=0)
            {
                subs.push_back(cnt);
                cnt = 0;
            }
            else if (x <= q)
                cnt++;
        }
        if (cnt!=0)
                subs.push_back(cnt);

        long long ans = 0;
        for (int i = 0; i < subs.size(); i++)
        {
            cnt = 0;
            for (int j = subs[i]-(k-1); j > 0; j--)
            {
                ans += j;
            }
        }
        cout << ans << endl;
    }
}
