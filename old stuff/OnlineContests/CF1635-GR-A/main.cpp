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
        ll x = 0, y = 0;

        vector<int> a(n);
        a.reserve(n);

        rep(i, n)
            cin >> a[i];

        string str = "NO";
        rep(i, n-1)
        {
            if (a[i] > a[i + 1])
            {
                str = "YES";
                break;
            }
        }
        cout << str << endl;
    }
}
