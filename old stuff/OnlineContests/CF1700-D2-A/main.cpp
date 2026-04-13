#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long sum = 0;
        for (int i = 0; i < m; i++)
            sum += i+1;
        for (int i = 1; i < n; i++)
            sum += i*m+m;
        cout << sum << endl;
    }
}
