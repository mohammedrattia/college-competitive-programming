#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long arr[2];
        long long num = -1000000005;
        long long a;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                cin >> a;
                if (a > num)
                {
                    arr[0] = i;
                    arr[1] = j;
                    num = a;
                }
            }
        }
        long long ans = max(n-arr[0], arr[0]+1)*max(m-arr[1], arr[1]+1);
        cout << ans << endl;
    }
}
