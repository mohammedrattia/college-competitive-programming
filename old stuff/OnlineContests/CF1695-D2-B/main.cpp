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
        int arr[51], num = 1000000005, idx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < num)
            {
                num = arr[i];
                idx = i;
            }
        }
        if (n % 2 != 0)
            cout << "Mike" << endl;
        else
        {
            if (idx % 2 == 0)
                cout << "Joe" << endl;
            else
                cout << "Mike" << endl;
        }
    }
}
