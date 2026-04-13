#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    int b = 0;
    set<int> arr;
    int g = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'G')
            {
                b = 1;
                g = j;
            }
            else if (b && str[j] == 'S')
            {
                b = 0;
                s = j;
                break;
            }
        }
        if (b)
        {
            cout << -1;
            return 0;
        }
        else
            arr.insert(s-g);
    }
    cout << arr.size();
}
