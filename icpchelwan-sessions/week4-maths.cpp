#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <climits>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <random>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll summation(ll n, ll a1 = -1, ll a2 = 1)
{
    if (a1 == -1)
        a1 = n;
    return n * (a1 + 1) / 2;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     ll a, b;
    //     cin >> a >> b;
    //     cout << lcm(a, b) << endl;
    // }
    // double x = 0.1, y = 0.2;
    // double z = x + y; // 0.3
    // cout << (z == (double)0.3) << endl;

    // double x = 0.1, y = 0.2;
    // double z = x + y; // 0.3
    // cout << 2 * (((ll)1e18 - 2) / 2) << endl;
    // cout << 2 * (ceil((ll)1e18 - 2) / 2) << endl;

    // double x = -0.1;
    // ll z = x;
    // if (x < 0)
    // {
    //     z--;
    // }
    // cout << z << endl;

    // int n;
    // cin >> n;
    // // 12-hours system
    // int hrsIn12 = n % 12;
    // if (hrsIn12 == 0)
    //     hrsIn12 += 12;

    // cout << hrsIn12 << ' ';
    // if (n % 12 == 0 && n != 12)
    // {
    //     cout << "am" << endl;
    // }
    // else if (n >= 12)
    // {
    //     cout << "pm" << endl;
    // }
    // else
    // {
    //     cout << "am" << endl;
    // }

    // int n;
    // cin >> n;
    // int arr[n];
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    //     sum += arr[i];
    //     sum %= MOD;
    // }
    // cout << sum << endl;

    // int a = 2000000000, b = 1000000000;
    // cout << (a * b) % MOD << endl;

    // sum 1 -> n
    // ll n;
    // cin >> n;
    // ll sum = 0;
    // for (int i = 1; i <= n / 2; i++)
    // {
    //     sum += n + 1;
    // }
    // cout << sum << endl;

    // ll n;
    // cin >> n;
    // ll sum = 0;
    // for (int i = 0; i <= n; i += 2)
    // {
    //     sum += i;
    // }
    //     ll divisors = n / 3;
    //     ll sum2 = 3 * summation(divisors);
    //     cout << sum << ' ' << sum2 << endl;

    // ll l, r;
    // cin >> l >> r;
    // ll sum = summation(r) - summation(l - 1);
    // ll even = summation(r / 2) - summation((l - 1) / 2);
    // even *= 2;
    // ll odd = sum - even;
    // cout << sum << ' ' << even << ' ' << odd;

    ll a, r;
    cin >> a >> r;
    ll n;
    cin >> n;
    ll a_n = a * pow(r, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /* code */
        }
    }

    cout << a_n << endl;
}
