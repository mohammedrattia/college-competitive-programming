#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x[n], y[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = y[i]-x[i];
        }
        sort(arr, arr+n);
        int a = 0, b = n-1, cnt = 0;
        while (a < b)
        {
            if (arr[a]+arr[b] >= 0)
            {
                cnt++;
                a++;
                b--;
            }
            else
            {
                a++;
            }
        }
        cout << cnt << endl;
    }
}
