#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<long long> arr;
        for (int i = 0; i < n; i++)
        {
            if (a[i]!=b[i])
                arr.push_back(i);
        }
        int s = arr.size();
        if (s == 0)
            cout << 0 << endl;
        else if (s%2 != 0)
            cout << -1 << endl;
        else
        {
            if (s >= 4)
                cout << min(x, y) * s/2 << endl;
            else
            {
                if (abs(arr[0]-arr[1]) == 1)
                    cout << min(x, y*2) << endl;
                else
                    cout << min(y, (abs(arr[0]-arr[1]))*x) << endl;
            }
        }
    }
}
