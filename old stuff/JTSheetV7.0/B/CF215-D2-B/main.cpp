#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    double n, r1 = 0, x;
    cin >> n;
    for (int i  = 0; i < n; i++)
    {
        cin >> x;
        r1 = max(r1, x);
    }
    double m, p1 = 0, y;
    cin >> m;
    for (int i  = 0; i < m; i++)
    {
        cin >> y;
        p1 = max(p1, y);
    }
    double k, p2 = 10000, z;
    cin >> k;
    for (int i  = 0; i < k; i++)
    {
        cin >> z;
        p2 = min(p2, z);
    }
    double a, b;
    cin >> a >> b;
    double r2 = sqrt((p1*pow(r1, 2))/(p2*((a/b)+(p1/p2))));
    cout << fixed << setprecision(20) << r2;
}
