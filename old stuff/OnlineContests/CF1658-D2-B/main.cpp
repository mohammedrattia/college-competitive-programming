#include <iostream>

using namespace std;

long long fac (long long n)
{
    if (n == 1)
        return 1;

    return (fac(n - 1) * n*n) % 998244353;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n % 2 == 0)
            cout << fac(n / 2) << endl;
        else cout << 0 << endl;
    }
}
