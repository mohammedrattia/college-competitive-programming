#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0, maxn = 0;
    int a[1000] = { 0 };
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        cnt = 1;

        int j = i;
        while (j != 0 && a[j] >= a[j - 1])
            cnt++, j--;

        j = i;
        while (j != n - 1 && a[j] >= a[j + 1])
            cnt++, j++;

        if (cnt > maxn)
            maxn = cnt;
    }
    cout << maxn;
}
