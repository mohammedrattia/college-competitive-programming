#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int x = a;
        int num = 1;
        while (true)
        {
            int a = x & 1;
            if (a == 1)
                break;
            num <<= 1;
            x = x >> 1;
        }
        if (num == a && num == 1)
            num = num + (num << 1);
        if (num == a)
            num = num + 1;

        cout << num << endl;
    }
}
