#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }
        sort(a, a+n);

        long long sum = 0;
        for (int i = 0; i < m; ++i)
        {
            a[0] = b[i];
            sort(a, a+n);
        }
        for (int i = 0; i < n; ++i)
        {
            sum += a[i];
        }
        cout << sum << endl;
    }
}
