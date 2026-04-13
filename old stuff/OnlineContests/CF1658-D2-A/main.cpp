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
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == str[i + 1] && str[i] == '0')
                sum += 2;
            else if (str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0')
                sum += 1;
        }

        cout << sum << endl;
    }
}
