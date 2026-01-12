#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int l = n+1, s = n-1;
    int arr[n];
    arr[0] = n;
    for (int i = 1; i < n; i++)
    {
        if (str[i-1] == '<')
        {
            arr[i] = s;
            s--;
        }
        else {
            arr[i] = l;
            l++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] -= s;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}