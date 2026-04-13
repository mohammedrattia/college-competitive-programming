#include <iostream>
#include <string>

using namespace std;

int main()
{
    string t = "SCPCTeensQual2024";
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 17; i++)
    {
        if (s[i] != t[i])
        {
            cnt++;
        }
    }
    cout << cnt;
}
