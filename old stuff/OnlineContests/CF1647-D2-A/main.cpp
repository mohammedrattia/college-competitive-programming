#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        if (n % 3 == 1)
            cout << 1;
        while (sum < (n / 3) * 3)
        {
            cout << 21;
            sum += 3;
        }
        if (n % 3 == 2)
            cout << 2;
        cout << endl;
    }
}
