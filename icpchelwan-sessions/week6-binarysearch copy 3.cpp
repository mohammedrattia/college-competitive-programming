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
        int a = binary_search(arr, arr + n, x);
        int b = lower_bound(arr, arr + n, x) - arr;
        int c = upper_bound(arr, arr + n, x) - arr;
        int cnt = upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x);
        cout << a << ' ' << b << ' ' << c << ' ' << cnt << endl;
    }
}