#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b)
{return a.second == b.second ? a.first < b.first :a.second > b.second;}

int main()
{
    double n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    double a, b;
    vector<pair<int, double>> arr;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        arr.push_back({i, max(a*t1*(1-k/100) + b*t2, b*t1*(1-k/100) + a*t2)});
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << arr[i].first << " " << arr[i].second << endl;
    }
}
