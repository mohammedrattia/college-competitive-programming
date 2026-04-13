#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    map<int, int> jump;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (mp.count(a) == 0)
        {
            jump[a] = 0;
        }
        else if (jump[a] == 0)
        {
            jump[a] = i - mp[a][0];
        }
        else if (i-mp[a][mp[a].size()-1]!=jump[a])
        {
            jump[a] = -1;
        }
        mp[a].push_back(i);
    }
    int cnt = 0;
    for (auto &e : mp)
    {
        if (jump[e.first] != -1)
            cnt++;
    }
    cout << cnt << endl;
    for (auto &e : mp)
    {
        if (jump[e.first] != -1)
            cout << e.first << " " << jump[e.first] << endl;
    }
}
