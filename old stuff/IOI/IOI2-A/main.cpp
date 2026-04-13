#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (int a,int b)
{
    return (a>b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort (a.begin(), a.end());
        sort (a.begin(), a.end() - 1, comp);

        int k = n - 1;
        bool b = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] <= k)
                k--;
            else if (a[i] > k)
            {
                cout << -1;
                b = 0;
                break;
            }
        }
        if (b)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}
