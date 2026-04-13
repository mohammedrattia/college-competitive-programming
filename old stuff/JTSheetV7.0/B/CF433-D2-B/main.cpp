#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> arr(n + 1);
    arr[0] = 0;
    for (long long i = 1; i <= n; i++)
        cin >> arr[i];

    vector<long long> arg = arr;
    sort(arg.begin(), arg.end());

    vector<long long> sum_arr(n + 1);
    vector<long long> sum_arg(n + 1);
    sum_arg[0] = sum_arr[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        sum_arr[i] = arr[i]+ sum_arr[i - 1];
        sum_arg[i] = arg[i]+ sum_arg[i - 1];
    }

    long long m;
    cin >> m;
    for (long long i = 0; i < m; i++)
    {
        long long type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
            cout << sum_arr[r] - sum_arr[l - 1] << endl;
        else
            cout << sum_arg[r] - sum_arg[l - 1] << endl;
    }
}
