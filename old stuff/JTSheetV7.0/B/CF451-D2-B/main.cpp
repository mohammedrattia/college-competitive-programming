#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 10e5 + 5;
int b[N], a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[b[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
    }

    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i)
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != i)
        {
            r = i;
            break;
        }
    }
    if (l == -1 || r == -1)
        cout << "yes\n" << 1 << " " << 1 << endl;
    else
    {
        reverse(a + l, a + r + 1);
        bool b = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != i)
            {
                b = false;
            }
        }
        if (b)
            cout << "yes\n" << l + 1 << " " << r + 1 << endl;
        else
            cout << "no" << endl;
    }
}
