#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    set<int> s;
    vector<int> arr;
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }
    for (auto i = s.begin(); i != s.end(); i++)
    {
        arr.push_back(*i);
    }
    if (arr.size() == 1)
        cout << "YES";
    else if (arr.size() == 3 && arr[2]-arr[1] == arr[1]-arr[0])
        cout << "YES";
    else if (arr.size() == 2)
        cout << "YES";
    else
        cout << "NO";
}
