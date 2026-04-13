#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int num = 0;
        bool b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                num++;
            }
            else
                b = 1;
        }
        if (b)
            cout << num << endl;
        else
        {
            vector<int> to_odd(n);
            for (int i = 0; i < n; i++)
            {
                int oper = 0;
                while (true)
                {
                    arr[i] /= 2;
                    oper++;
                    if (arr[i] % 2 != 0)
                    {
                        to_odd[i] = oper;
                        break;
                    }
                }
            }
            sort(to_odd.begin(), to_odd.end());
            cout << num + to_odd[0] - 1 << endl;
        }
    }
}
