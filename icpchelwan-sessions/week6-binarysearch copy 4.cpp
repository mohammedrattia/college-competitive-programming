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

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    while (m--)
    {
        int x;
        cin >> x;
        int c = upper_bound(arr, arr + n, x) - arr;
        cout << c << ' ';
    }
}