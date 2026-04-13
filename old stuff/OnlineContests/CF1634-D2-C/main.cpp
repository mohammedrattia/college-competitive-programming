//Wrong
#include <iostream>

using namespace std;

int a[500][500] = { 0 };

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > 2)
            cout << "NO" << endl;
        else
        {
            if (k == 2 && (n % 2 != 0 || n == 1))
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                int num = 1;
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        a[j][i] = num++;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < k; j++)
                    {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}
