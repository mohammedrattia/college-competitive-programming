#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string ans = "YES";
        for (long long i = 0; i < n; i++)
        {
            for (long long j = i+1; j < n; j++)
            {
                if (abs(arr[i]-arr[j]) == 0)
                    ans = "NO";
            }
        }
        cout << ans << endl;
    }
}
