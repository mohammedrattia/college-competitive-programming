#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if (k > 32)
            cout << n+1 << endl;
        else
        {
            long long c = pow(2, k);
            cout << min(n+1, c) << endl;
        }
    }
}
