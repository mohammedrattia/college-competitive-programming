#include <iostream>
#include <cstring>

using namespace std;

bool b[200005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(b, 0, sizeof(b));

        int num = 0;
        cout << 2 << endl;
        int i = 1;
        bool x = 1;
        int idx = 0;

        while (num != n)
        {
            if (x)
            {
                idx = i+1;
                x = 0;
            }
            if (!b[i])
            {
                cout << i << ' ';
                num++;
                b[i] = 1;
                i *= 2;
                if (i > n)
                {
                    i = idx;
                    x = 1;
                }
            }
            else
            {
                i++;
                idx++;
            }
        }
        cout << endl;
    }
}
