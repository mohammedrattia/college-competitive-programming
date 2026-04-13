#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> a;
            sum += a;
        }
        if (sum == 0)
            cout << 0 << endl;
        else if (sum == 4)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}
