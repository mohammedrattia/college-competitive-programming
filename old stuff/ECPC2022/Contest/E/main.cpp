#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    //freopen("min.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = (int)log2(n)+1;
        int x = 0;
        rep(i, l)
        {
            x <<= 1;
            x |= 1;
        }
        x ^= n;
        cout << x << endl;
    }
}
