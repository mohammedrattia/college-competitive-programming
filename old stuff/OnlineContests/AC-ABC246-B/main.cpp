#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;

    double len = sqrt(x*x + y*y);
    cout << fixed << setprecision(10) << x/len << " " << y/len;
}
