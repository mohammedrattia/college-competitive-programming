#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int, vector<int>> pq;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            pq.push(arr[i]);
        }
        else if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}