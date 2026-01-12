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
        cin >> arr[i];

    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (l == n - 1 && arr[l] < x)
            cout << -1 << endl;
        else
            cout << l + 1 << endl;
    }
}