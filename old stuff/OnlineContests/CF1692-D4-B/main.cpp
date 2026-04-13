#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        set<int> dist;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            dist.insert(arr[i]);
        }
        cout << (int)(dist.size() - ((arr.size() - dist.size())%2)) << endl;
    }
}
