#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[0]%2 == arr[i]%2)
            {
                idx = i;
            }
        }
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            if (arr[idx]%2 == arr[i]%2 && idx!=i)
            {
                vec.push_back(make_pair(i+1, idx+1));
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[0]%2 != arr[i]%2 && i!=0)
            {
                vec.push_back(make_pair(1, i+1));
            }
        }
        cout << vec.size() << endl;
        for (auto &e:vec)
            cout << e.first << ' ' << e.second << endl;
    }
}
