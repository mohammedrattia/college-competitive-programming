#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    freopen("fair.in", "r", stdin);
    int n;
    cin >> n;
    int a;
    int sum1 = 0, sum2 = 0;
    rep(i, n)
    {
        cin >> a;
        sum1 += a;
    }
    rep(i, n)
    {
        cin >> a;
        sum2 += a;
    }
    if (sum1 == sum2)
        cout << "fair" << endl;
    else cout << "not fair" << endl;
}
