#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

int n;
vector<ll> a;

string solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (a[j] > a[j + 1] && ((a[j] + a[j + 1]) % 2 == 0))
                return "No";
            else if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            else
                break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            if (a[j - 1] > a[j] && ((a[j] + a[j - 1]) % 2 == 0))
                return "No";
            else if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
            else
                break;
        }
    }
    return "Yes";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.reserve(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve() << endl;
    }
}
