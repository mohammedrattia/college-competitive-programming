#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

vector<int> arr;
int mem[5001][5001];
vector<pair<int, int>> freq;

int solve(int s = 0, int e = freq.size()-1, int num = 0)
{
    if (s > e)
        return 0;
    int &ret = mem[s][e];
    if (ret != -1)
        return ret;
    ret = num;
    if (freq[s].first*2 < freq[e].first)
    {
        int a = solve(s+1, e, num+freq[s].second);
        int b = solve(s, e-1, num+freq[e].second);
        ret = min(a, b);
    }
    return ret;
}

int main()
{
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    arr = vector<int>(5001, 0);
    memset(mem, -1, sizeof(mem));
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]!= 0)
            freq.push_back(make_pair(i, arr[i]));
    }
    /*
    for (auto &e:freq)
        cout << e.first << " " << e.second << endl;
    */
    cout << solve();
}
