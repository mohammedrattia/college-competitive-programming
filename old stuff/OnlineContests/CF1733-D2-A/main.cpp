#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < k; i++)
        {
            for (int j = k+i; j < n; j+=k)
            {
                arr[i] = max(arr[i], arr[j]);
            }
        }
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        cout << sum << endl;
    }
}
