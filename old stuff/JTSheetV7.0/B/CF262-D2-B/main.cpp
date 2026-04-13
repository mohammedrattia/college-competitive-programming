#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int i = 0;
    while (arr[i] < 0)
    {
        arr[i] *= -1;
        i++;
        k--;
        if (k == 0)
            break;
    }
    sort(arr, arr+n);
    if (k != 0)
    {
        while (k--)
        {
            arr[0] *= -1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum;
}
