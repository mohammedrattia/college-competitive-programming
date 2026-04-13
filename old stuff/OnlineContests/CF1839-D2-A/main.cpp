#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0, cur = 0;
        int arr[n] = { 0 };
        for (int i = 1; i <= n; i++)
        {
            //cout << ((i/k) + (i%k != 0)) << ' ' << last << endl;
            cur+= arr[i-1];
            if (((i/k) + (i%k != 0)) > cur)
            {
                arr[i-1] = 1;
                if (i <= (n/2 + n%2))
                    arr[n-i] = 1;
                cur++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans+=arr[i];
        }
        cout << ans << endl;
    }
}
