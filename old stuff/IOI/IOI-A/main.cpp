#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[101] = { 0 };

        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        if (k % 2 != 0)
        {
            int num = (k - 1)/2 + 1;
            if (num == n)
            {
                a[num - 1] = a[num - 3];
                a[num - 3] = num;
                int temp = a[num - 1];
                a[num - 1] = a[num - 2];
                a[num - 2] = temp;
            }
            else
            {
                a[num - 1] = a[num];
                a[num] = num;
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
    }
}
