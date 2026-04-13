#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        a.reserve(n);
        bool wrong = 1;
        ll sum = 0;
        rep(i, n)
        {
            cin >> a[i];
            if (i > 0 && i < n - 1)
            {
                sum += a[i] + (a[i] % 2);
                if (a[i] != 1)
                    wrong = 0;
            }
        }
        if (wrong || (n == 3 && (a[1] % 2 != 0)))
            cout << -1 << endl;
        else
            cout << sum / 2 << endl;
    }
}
