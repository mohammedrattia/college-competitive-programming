#include <iostream>
#include <string>

using namespace std;

string str;
int n, q, num_sub = 0;

void check(int i, char a, int sign)
{
    if (a == 'a')
    {
        if (str[i + 1] == 'b' && str[i + 2] == 'c')
            num_sub+=sign;
    }
    else if (a == 'b')
    {
        if (str[i - 1] == 'a' && str[i + 1] == 'c')
            num_sub+=sign;
    }
    else
    {
        if (str[i - 2] == 'a' && str[i - 1] == 'b')
            num_sub+=sign;
    }
}

int main()
{
    cin >> n >> q;
    cin >> str;
    for (int i = 0; i < n - 2; i++)
    {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            num_sub++;
            i += 2;
        }
    }
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        check(x - 1, str[x - 1], -1);
        str[x - 1] = c;
        check(x - 1, c, 1);
        cout << num_sub << endl;
    }
    return 0;
}
