#include <bits/stdc++.h>


using namespace std;

long long ans = 0;
long long n, x;
long long arr[200];
long long mem[101][100005];

long long solve(long long i = 0, long long sum = 0)
{
if (i == n)
{
    if (sum == 0)
        return 0;
    return 1e-9;
}

int &ret = mem[i][sum];
if (ret != -1)
    return ret;

int ret = solve(i+1, sum + arr[i] + 1);
int ret = solve(i+1, sum + arr[i]);
int ret = solve(i+1, sum + arr[i] - 1);
int ret = solve(i+1, sum);
return 0;
}

int main()
{
long long t;
cin >> t;
while (t--)
{
    ans = 0;
    cin >> n >> x;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve();
    cout << ans << endl;
}
}
