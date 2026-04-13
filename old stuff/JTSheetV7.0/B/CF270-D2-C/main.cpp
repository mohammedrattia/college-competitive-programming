#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long>> arr(n);
    arr.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    long long boxs;
    for (long long i = 0; i < n-1; i++)
    {
        boxs = arr[i].second;
        if (arr[i+1].first - arr[i].first <= 15)
        {
            for (long long j = arr[i].first; j < arr[i+1].first; j++)
            {
                boxs = boxs/4 + (boxs%4 != 0);
            }
            arr[i+1].second = max(boxs, arr[i+1].second);
        }
    }
    boxs = arr[n-1].second;
    long long sz = arr[n-1].first;
    while (boxs > 1 || sz <= arr[n-1].first)
    {
        boxs = boxs/4 + (boxs%4 != 0);
        sz++;
    }
    cout << sz << endl;
}
