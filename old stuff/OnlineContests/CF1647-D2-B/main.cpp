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

        string a[105] = {""};
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool b = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int x = int(a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] - int('0') * 4);
                if (x == 3)
                    b = 1;
                if (b)
                    break;
            }
            if (b)
                break;
        }

        if (b)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }
}
