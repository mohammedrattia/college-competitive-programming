#include <iostream>
#include <algorithm>

using namespace std;

const long long N = 10e5 + 5;
long long k[N], l[N], d[N];

int main()
{
    long long n, f;
    cin >> n >> f;
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> k[i] >> l[i];
        sum += min(k[i], l[i]);
    }

    for (long long i = 0; i < n; i++)
    {
        d[i] = min(2 * k[i], l[i]) - min(k[i], l[i]);
    }
    sort(d, d+n);
    for (long long i = n-1; i >= n-f; i--)
    {
        sum += d[i];
    }
    cout << sum;
}
