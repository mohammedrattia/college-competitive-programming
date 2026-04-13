#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, x, y;
    cin >> n >> k;
    int arr[n+1] = {0};
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        arr[x] += 1;
        arr[y+1] += -1;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
    }
    sort(arr, arr+n+1);
    cout << arr[n/2+1] << endl;
}
