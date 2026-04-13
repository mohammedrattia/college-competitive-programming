#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.size();
        cout << abs(str[0]-str[n-1]) << " ";
        vector<pair<char, int>> v;
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= min(str[0], str[n-1]) && str[i] <= max(str[0], str[n-1]))
                v.push_back({str[i], i+1});
        }
        cout << v.size() << endl;
        if (str[0] <= str[n-1])
            sort(v.begin()+1, v.end()-1);
        else sort(v.rbegin()+1, v.rend()-1);
        for (int i = 0; i < v.size(); i++)
            cout << v[i].second << " ";
        cout << endl;
    }
}
