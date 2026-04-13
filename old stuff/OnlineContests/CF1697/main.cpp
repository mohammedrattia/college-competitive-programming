#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int sum = 0, a = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }
        cout << (m > sum ? 0 : (sum - m)) << endl;
    }
}
