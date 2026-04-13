#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (x != 0 && y != 0)
            cout << -1 << endl;
        else if (x == 0 && y == 0)
            cout << -1 << endl;
        else if ((n-1)%max(x, y) != 0)
            cout << -1 << endl;
        else
        {
            for (int i = 2; i <= n; i+=max(x, y))
            {
                for (int j = 0; j < max(x, y); j++)
                    cout << i << " ";
            }
            cout << endl;
        }
    }
}
