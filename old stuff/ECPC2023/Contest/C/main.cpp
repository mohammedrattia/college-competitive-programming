#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int t = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S' && t<a+b)
        {
            t++;
            cout << "Yes" << endl;
        }
        else if (s[i] == 'E' && t<a+b && e<b)
        {
            t++;
            e++;
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
