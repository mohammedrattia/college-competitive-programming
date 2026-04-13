#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    long long num = 0;
    for (long long i = 1; i <= k; i++)
        num += arr[i];
    long long idx = 1;

    int min_num = num;
    for (long long i = 2; i <= n - k + 1; i++)
    {
        num = num - arr[i - 1] + arr[i + k - 1];
        if (min_num > num)
        {
            idx = i;
            min_num = num;
        }
    }
    cout << idx;
}
