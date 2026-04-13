#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str.find("MOO") != string::npos)
            cout << str.size()-3 << endl;
        else if (str.find("OOO") != string::npos)
            cout << str.size()-3+1 << endl;
        else if (str.find("MOM") != string::npos)
            cout << str.size()-3+1 << endl;
        else if (str.find("OOM") != string::npos)
            cout << str.size()-3+2 << endl;
        else
            cout << -1 << endl;
    }

}
