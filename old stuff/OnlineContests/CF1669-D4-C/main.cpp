#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, c;
        cin >> a >> c;
        bool b = 1;
        for (int i = 2; i < n; i++)
        {
            int e;
            cin >> e;
            if (i%2 == 0 && e%2 != a%2 && b)
            {
                cout << "NO" << endl;
                b = 0;
            }
            else if (i%2 != 0 && e%2 != c%2 && b)
            {
                cout << "NO" << endl;
                b = 0;
            }
        }
        if (b)
            cout << "YES" << endl;
    }
}
