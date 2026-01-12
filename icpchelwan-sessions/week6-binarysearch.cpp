#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

int main()
{
    FAST;

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1, ans = -2;
        while (l <= r)
        {
            int mid = l + (r - l + 1) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                break;
            }
            else if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans + 1 << endl;
    }
}