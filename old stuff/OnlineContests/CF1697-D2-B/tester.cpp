#include <iostream>
#include <algorithm>

using namespace std;

long long arr[2*100000+5];

int main()
{
    long long n, q;
    cin >> n >> q;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (long long i = 1; i < n; i++)
    {
        arr[i] += arr[i-1];
    }

    while(q--)
    {
        long long x, y;
        cin >> x >> y;
        cout << arr[n - x + y - 1] - arr[n - x - 1] << endl;
    }
}
