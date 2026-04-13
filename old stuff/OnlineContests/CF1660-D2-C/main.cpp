#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define ll long long
#define rep(i, n) for (long long i = 0; i < n; i++)

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        rep (i, str.size() - 1)
        {
            if (str[i] == str[i + 1])
            {
                str.erase(str.begin() + i, str.begin() + i + 2);
                i--;
            }
        }
        cout << str << endl;

        map<char, vector<int>> graph;
        map<char, int> nums;
        rep (i, str.size())
        {
            graph[str[i]].push_back(i);
            nums[str[i]]++;
        }
    }
}
