#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

vector<int> arr;

int main()
{
    freopen("game.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        arr = vector<int>(n, 0);
        rep(i, n)
        {
            cin >> arr[i];
        }
        bool b = 1;
        while (!arr.empty())
        {
            arr.erase(max_element(arr.begin(), arr.end()), arr.end());
            b = !b;
        }
        if (b)
            cout << "Jack" << endl;
        else cout << "Mike" << endl;
    }
}
