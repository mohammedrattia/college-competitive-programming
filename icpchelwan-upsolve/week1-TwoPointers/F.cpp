/*
Step-by-step algorithm:
    * Maintain two pointers, say start = 0 and end = 0 to mark the starting and ending of sliding window.
    * Maintain a variable sum = 0 to store the sum of all elements from start to end.
    * Maintain a variable cnt = 0 to store the number of subarrays having sum = X.
    * Keep increasing the size of sliding window my moving forward the end pointer till sum < X.
    * Now, if the sum has become greater than X, we decrease the size of sliding window by moving forward the start pointer.
    * After moving the start pointer, if the sum is equal to X, increment cnt by 1.
    * After iterating over all the elements, print cnt as the final answer.
*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long l = 0, r = 0, sum = 0, cnt = 0;
    while (r != n)
    {
        if (sum < x)
        {
            sum += arr[r++];
        }
        else
        {
            while (sum >= x)
            {
                if (sum == x) // 1 2 5
                    cnt++;
                sum -= arr[l++];
            }
        }
    }
    while (sum > x)
    {
        sum -= arr[l++];
    }
    if (sum == x)
        cnt++;
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
