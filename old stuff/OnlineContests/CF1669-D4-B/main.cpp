#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 2, 0);
        bool b = 1;
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            a[e]++;
            if (a[e] == 3 && b)
            {
                b = 0;
                cout << e << endl;
            }
        }
        if (b)
            cout << -1 << endl;
    }
}
