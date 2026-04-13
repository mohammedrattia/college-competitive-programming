#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        bool is_there_odd = 0;
        int mxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[mxi] < a[i] || mxi == 0)
                mxi = i;
        }
        int r = 0, l = 0;
        if (a[0] >= a[mxi])
        {
            if (mxi == n-1)
            {
                r = mxi;
                l = mxi;
            }
            else
            {
                r = mxi-1;
                l = mxi-1;
                while (a[l-1] > a[0])
                {
                    l--;
                }
            }
        }
        else if (mxi == n-1)
        {
            if (a[mxi-1] < a[0])
            {
                r = mxi;
                l = mxi;
            }
            else
            {
                r = mxi-1;
                l = mxi-1;
                while (a[l-1] > a[0])
                {
                    l--;
                }
            }
        }
        else
        {
            r=mxi-1;
            l=mxi-1;
            while (a[l-1] > a[0])
            {
                l--;
            }
        }
        for (int i = r+1; i < n; i++)
            cout << a[i] << ' ';
        for (int i = r; i >= l; i--)
            cout << a[i] << ' ';
        for (int i = 0; i < l; i++)
            cout << a[i] << ' ';

        cout << endl;
    }
}
