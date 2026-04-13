#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<string, vi> arr;
        string str;
        int cnt[3] = { 0 };
        rep(i, 0, 3)
        {
            rep(j, 0, n)
            {
                cin >> str;
                arr[str].push_back(i);
            }
        }
        for (auto &e : arr)
        {
            if (e.second.size()==1)
            {
                cnt[e.second[0]] += 3;
            }
            else if (e.second.size()==2)
            {
                cnt[e.second[0]]++;
                cnt[e.second[1]]++;
            }
        }
        cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
    }
}
