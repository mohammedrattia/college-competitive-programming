#include <iostream>

using namespace std;

long double e = 1e-12;

int main()
{
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    if (vp > vd)
    {
        cout << 0;
        return 0;
    }

    long double esq = vp*t;
    long double delta = vp*t;
    int ans = 0;

    while (esq + e < c)
    {
        delta = (long double)(esq/(vd-vp))*vd;

        if (delta + e < c)
        {
            long double hrs = (long double)(2.0*(esq/(vd-vp)) + f);
            esq += vp*hrs;
            ans++;
        }
        else break;
    }
    cout << ans;
}
