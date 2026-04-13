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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            is_there_odd = max(is_there_odd, a[i]%2==1);
        }
        if (is_there_odd)
        {
            sort(a, a+n);
            if (a[0]%2)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
