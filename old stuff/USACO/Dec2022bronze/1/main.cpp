#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long c[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }
    sort(c, c+n);
    long long maxi = 0;
    long long profit = c[0]*n;/*
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = c[i]*(n-i);
    }*/
    for (int i = 1; i < n; ++i)
    {
        if (c[i]*(n-i) > profit)
        {
            profit = c[i]*(n-i);
            maxi = i;
        }
    }
    cout << c[maxi]*(n-maxi) << ' ' << c[maxi];
}
