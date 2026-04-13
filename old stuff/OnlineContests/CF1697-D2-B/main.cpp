#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    /*int t = 1000;
    while (t--)
    {*/
        long long n;// = rand() % 100
        long long q;// = rand() % 10000;
        cin >> n >> q;
        long long arr[2*100000+5] = { 0 };
        long long presum[2*100000+5] = { 0 };

        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];// = rand() % 1000;
        }
        sort(arr, arr+n);
        presum[0] = arr[0];
        for (long long i = 1; i < n; i++)
        {
            presum[i] = arr[i] + presum[i-1];
        }

        while(q--)
        {
            long long x;// = rand() % n + 1;
            long long y;// = rand() % x + 1;
            cin >> x >> y;
            /*int sum = 0;
            for (int i = n - x; i < n - x + y; i++)
                sum += arr[i];

            if (sum != presum[n - x + y - 1] - presum[n - x - 1])
            {
                cout << n << " " << q << endl;
                for (int i = 1; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
                for (int i = 1; i < n; i++)
                {
                    cout << presum[i] << " ";
                }
                cout << "\n" << x << " " << y << "\n";
                cout << sum << " " << presum[n - x + y - 1] - presum[n - x - 1] << "\n\n";
            }*/
            cout << presum[n - x + y - 1] - presum[n - x - 1] << endl;
        }
    //}
    return 0;
}
