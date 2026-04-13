#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (m<n)
            cout << "No" << endl;
        else if (n%2 == 0)
        {
            if (m%2 == 0)
            {
                cout << "Yes" << endl;
                for (int i = 0; i < n-2; i++)
                {
                    cout << 1 << ' ';
                }
                cout << (m-(n-2))/2 << ' ' << (m-(n-2))/2 << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n-1; i++)
            {
                cout << 1 << ' ';
            }
            cout << m-(n-1) << endl;
        }
    }
}
