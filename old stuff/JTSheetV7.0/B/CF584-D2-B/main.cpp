#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a = 1, b = 1;
    for (int i = 0; i < n; i++)
    {
        a *= 27;
        a %= 1000000007;
        b *= 7;
        b %= 1000000007;
    }
    cout << (a-b)%1000000007 + ((a >= b) ? 0 : 1000000007);
}
