#include <iostream>

using namespace std;

int a[200005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int pos = 0, neg = 0;
        int idxp = 0, idxn = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                pos++, idxp = i;
            else if (a[i] < 0)
                neg++, idxn = i;
            sum += a[i];
        }

        if (neg > 1 || pos > 1 && sum != a[0] && sum != a[1] && sum != a[2])
            cout << "NO" << endl;
        else if (a[idxp] + a[idxn] != 0)
            cout << "NO" << endl;
        else cout << "YES" << endl;

        /*for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                for (int k = j; k < n; k++)
                {
                    int sum = a[i] + a[j] + a[k];
                    if (sum != a[i] && sum != a[j] && sum != a[k])
                    {
                        b = 1;
                        break;
                    }
                }
            }
        }*/
    }
}
