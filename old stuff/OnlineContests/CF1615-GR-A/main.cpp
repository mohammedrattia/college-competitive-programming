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
        int a, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }
        cout << (sum % n != 0) << endl;
    }
}
