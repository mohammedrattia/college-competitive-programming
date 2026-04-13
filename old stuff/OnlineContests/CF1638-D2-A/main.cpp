#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        p.reserve(n);
        int l = 0, r = 0;
        bool b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] != (i + 1) && b == 0)
            {
                l = i;
                b = 1;
            }
            else if (p[i] == (l + 1) && b == 1)
                r = i;
        }
        while (r > l)
            swap(p[l++], p[r--]);

        for (int i = 0; i < n; i++)
            cout << p[i] << ' ';
        cout << endl;
    }
}
