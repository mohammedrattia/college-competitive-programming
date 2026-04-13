#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    freopen("stock.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        cout << y-x << endl;
    }
}
