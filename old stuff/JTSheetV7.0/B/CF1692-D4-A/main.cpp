#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[4];
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        int go = a[0];
        sort(a, a+4);
        for (int i = 0; i < 4; i++)
        {
            if (a[i] == go)
                cout << 4-i-1 << endl;
        }
    }
}
