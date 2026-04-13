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
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            arr[i] = e;
        }

        int b = 0, a = 0;
        int wb = 0, wa = 0;
        int mb = 0, ma = 0;
        int r = n - 1, l = 0;

        while (b + a != n)
        {
            if (wa == wb)
            {
                mb = b;
                ma = a;
            }
            if (wa >= wb)
            {
                wb += arr[r];
                r--;
                b++;
            }
            else if (wa < wb)
            {
                wa += arr[l];
                l++;
                a++;
            }
        }
        if (wa == wb)
        {
            mb = b;
            ma = a;
        }
        cout << mb + ma << endl;
    }
}
