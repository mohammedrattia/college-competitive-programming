#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int freq[200005] = { 0 }, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            freq[x]++;
        }
        int can = 0, ans = 0;
        for (int i = 0; i < 200005; i++)
        {
            if (freq[i] < k && freq[i] > 0)
            {
                can += k - freq[i];
            }
            else if (freq[i] > k && freq[i] > 0)
            {
                can -= freq[i] - k;
                ans += freq[i] - k;
            }
        }
        if (can >= 0)
            cout << ans << endl;
        else cout << -1 << endl;
    }
}
