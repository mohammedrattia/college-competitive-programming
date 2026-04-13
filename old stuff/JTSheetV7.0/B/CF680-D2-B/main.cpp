#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int t[101] = { 0 };
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int i = 0, cnt = t[--a];

    while (++i)
    {
        if (a - i < 0 && a + i >= n)
            break;
        else if (a - i < 0)
        {
            for (int j = a + i; j < n; j++)
                cnt += t[j];
            break;
        }
        else if (a + i >= n)
        {
            for (int j = a - i; j >= 0; j--)
                cnt += t[j];
            break;
        }
        else if (t[a + i] + t[a - i] == 2)
            cnt += 2;
    }
    cout << cnt;
}
