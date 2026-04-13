#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    freopen("files.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        int id;
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> str >> id;
            if (!mp.count(str))
                mp[str] = 1000000;
            mp[str] = min(mp[str], id);
        }
        auto it = begin(mp);
        vector<int> arr;
        for (auto e : mp)
        {
            arr.push_back(e.second);
        }
        sort(arr.begin(), arr.end());
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
    }
}
