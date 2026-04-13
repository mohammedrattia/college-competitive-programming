#include <iostream>

using namespace std;

int main()
{
    int p, q, l, r;
    int x[55][2], z[55][2];
    cin >> p >> q >> l >> r;

    for (int i = 0; i < p; i++)
        cin >> z[i][0] >> z[i][1];
    for (int i = 0; i < q; i++)
        cin >> x[i][0] >> x[i][1];

    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        bool b = 0;
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < q; k++)
            {
                int s = x[k][0] + i;
                int e = x[k][1] + i;
                if (!(e < z[j][0] || s > z[j][1]))
                {
                    ans++;
                    b = true;
                    break;
                }
            }
            if (b) break;
        }
    }
    cout << ans;
}
