#include <iostream>
#include <vector>

using namespace std;

void setIO(string s)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("maxcross");
    long long n, k, b;
    cin >> n >> k >> b;
    long long arr[n+1] = {0};
    long long x, mn = 10000000000000;
    for (long long i = 1; i <= b; i++)
    {
        cin >> x;
        arr[x] = 1;
    }
    for (long long i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
    }
    for (long long i = 0; i+k <= n; i++)
    {
        mn = min(arr[i+k]-arr[i], mn);
    }
    cout << mn;
}
