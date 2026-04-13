#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int idx[26] = {0};
    int j = 0;
    //cout << str.size() << endl;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '?')
            continue;
        else if (idx[str[i]-'A'] == 0)
        {
            idx[str[i]-'A'] = i+1;
        }
        else
        {
            j = idx[str[i]-'A']+1;
            for (int l = 0; l < 26; ++l)
            {
                if (idx[l] < j && idx[l] != 0)
                    idx[l] = 0;
            }
            idx[str[i]-'A'] = i+1;
        }
        if (str.size()-j+1 < 26)
        {
            cout << -1;
            return 0;
        }
        if (i-j==26)
        {
            break;
        }
    }
    int k = 0;
    for (int i = j; i < j+26; ++i)
    {
        if (str[i] == '?')
        {
            while (idx[k] != 0)
            {
                k++;
            }
            str[i] = (char)(k++ + 'A');
        }
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '?')
        {
            str[i] = 'A';
        }
    }
    cout << str;
}
