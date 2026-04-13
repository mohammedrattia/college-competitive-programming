#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < abs(b-c)+c)
            cout << 1 << endl;
        else if (a > abs(b-c)+c)
            cout << 2 << endl;
        else cout << 3 << endl;
    }
}
