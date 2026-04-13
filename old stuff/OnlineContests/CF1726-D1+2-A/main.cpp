#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n], maxi = 0, mini = 0, best = 0;
        rep(i, 0, n)
        {
            cin >> arr[i];
            if (arr[i] < arr[mini])
                mini = i;
            if (arr[i] > arr[maxi])
                maxi = i;
            if (i > 0)
                best = max(best, arr[i-1]-arr[i]);
        }
        cout << max((arr[maxi]-arr[0]), max((arr[n-1]-arr[mini]), best)) << endl;
    }
}
