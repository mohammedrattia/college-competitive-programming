#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long x, y;
    cin >> x >> y;
    long long k;
    cin >> k;
    long long ans = 0;
    while (k--)
    {
        long long dx, dy;
        cin >> dx >> dy;

        long long stepsx, stepsy;
        if (dx > 0)
            stepsx = (n-x)/dx;
        else if (dx < 0)
            stepsx = (1-x)/dx;
        else
            stepsx = 1000000005;

        if (dy > 0)
            stepsy = (m-y)/dy;
        else if (dy < 0)
            stepsy = (1-y)/dy;
        else
            stepsy = 1000000005;

        long long steps = min(stepsx, stepsy);
        ans += steps;
        x += steps*dx;
        y += steps*dy;
    }
    cout << ans;
}
