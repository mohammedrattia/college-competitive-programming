#include <iostream>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)

int divs(int n)
{
    int cnt = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n/i == i)
                cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    long long num = 1073741824;
    long long ans = 0;
    rep(i, 1, a)
    {
        rep(j, 1, b)
        {
            rep(k, 1, c)
            {
                ans += divs(i*j*k) % num;
            }
        }
    }
    ans %= num;
    cout << ans;
}
