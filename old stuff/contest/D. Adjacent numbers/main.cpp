#include <iostream>

using namespace std;

int main()
{
    int n, k, a, b;
    cin >> n >> k;
    cin >> a;
    int cnt = 1, maxcnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b;
        cnt++;
        if (a != b)
        {
            if (cnt >= maxcnt)
                maxcnt = cnt;
        }
        else
            cnt = 1;
        a = b;
    }
    cout << maxcnt;
}
