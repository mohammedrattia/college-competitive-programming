#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100005];

int main()
{
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    bool b = 0;
    for (long long i = 2; i < n; i++)
    {
        if (arr[i-2] + arr[i-1] > arr[i])
        {
            b = 1;
            break;
        }
    }
    if (b)
        cout << "YES";
    else
        cout << "NO";
}
