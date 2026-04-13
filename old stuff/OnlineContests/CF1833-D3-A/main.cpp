#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        map<string, int> mp;
        for (int i = 0; i < n-1; i++)
        {
            mp[str.substr(i, 2)]++;
        }
        cout << mp.size() << endl;
    }
}
