#include <iostream>
#include <string>

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
        bool b = 0, r = 0, ch = 1;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'R')
                r = 1;
            else if (str[i] == 'B')
                b = 1;
            else
            {
                if (r != b)
                {
                    cout << "NO" << endl;
                    ch = 0;
                    break;
                }
                else
                {
                    r = 0;
                    b = 0;
                }
            }
        }

        if (r != b && ch)
        {
            cout << "NO" << endl;
        }
        else if (ch)
            cout << "YES" << endl;
    }
}
