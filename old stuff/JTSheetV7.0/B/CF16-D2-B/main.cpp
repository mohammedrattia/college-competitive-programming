#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> arr;

    for (int i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end(), comp);

    long long cnt = 0, i = 0, sum = 0;
    while (n - cnt > 0 && i < m)
    {
        sum += ((n - cnt) > arr[i].first ? arr[i].first : n - cnt) * arr[i].second;
        cnt += arr[i++].first;
    }
    cout << sum;
}
