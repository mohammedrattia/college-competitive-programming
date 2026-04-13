#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    a.reserve(n);
    long long item;
    for (long long i = 0; i < n; i++)
    {
        cin >> item;
        a[i] = item - min(item / x, k)*x;
        k -= min(item / x, k);
    }
    if (k >= n)
        cout << 0;
    else
    {
        long long price = 0;
        sort(a.begin(), a.end());
        for (long long i = 0; i < n - k; i++)
            price += a[i];
        cout << price;
    }
}
