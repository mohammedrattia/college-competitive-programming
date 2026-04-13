#include <iostream>

using namespace std;

int a[200005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i >= 2 && a[i-1] > a[i-2] + a[i])
                num++;
        }
        if (k == 1)
            cout << (n/2) - !(n%2) << endl;
        else cout << num << endl;
    }
}
