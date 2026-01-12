#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;
// const double ESP = 1e-7;

ll n, k;

int numOfRobes(double len, int arr[])
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += floor(arr[i] / len);
    }
    return cnt;
}

int main()
{
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double l = 0, r = 1e7;
    for (int i = 0; i < 50; i++)
    {
        double mid = l + (r - l) / 2;
        if (numOfRobes(mid, arr) >= k)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << fixed << setprecision(7) << l << endl;
}