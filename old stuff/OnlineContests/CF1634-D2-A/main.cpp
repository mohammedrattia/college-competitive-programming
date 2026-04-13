#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string str = "";
        cin >> n >> k >> str;
        bool check = 1;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != str[n - i - 1])
            {
                check = 0;
                break;
            }
        }
        if (check || k == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}
