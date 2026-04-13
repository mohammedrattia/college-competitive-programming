#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int val[3] = { 0 };
    for (int i = 0; i < 3; i++)
    {
        cin >> str;
        if (str[1] == '<')
            val[str[2] - 'A']++;
        else if (str[1] == '>')
            val[str[0] - 'A']++;
    }
    for (int i = 0; i < 2; i++)
    {
        if (val[i] == val[i + 1])
        {
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0; i < 3; i++)
        str[val[i]] = (char)('A' + i);
    cout << str;
}
