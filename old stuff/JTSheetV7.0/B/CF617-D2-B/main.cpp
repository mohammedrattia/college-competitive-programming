#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0, e = n-1;
    while (arr[s] == 0)
    {
        s++;
        if (s == n)
        {
            cout << 0;
            return 0;
        }
    }
    while (arr[e] == 0)
        e--;

    long long num = 1;
    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] == 1)
        {
            num *=cnt+1;
            cnt = 0;
        }
        else cnt++;
    }
    cout << num;
}
