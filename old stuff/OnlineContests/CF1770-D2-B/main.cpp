#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >>t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a = n, b = 1;
        for (int i = 0; i < n; i++)
        {
            if ((i+1)%k == 0)
                cout << b++ << ' ';
            else cout << a-- << ' ';
        }
        cout << endl;
    }
}
