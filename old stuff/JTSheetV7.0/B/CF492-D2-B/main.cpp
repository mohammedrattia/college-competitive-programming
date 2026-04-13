#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    long long n, l, x;
    cin >> n >> l;
    vector<long long> lanterns;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        lanterns.push_back(x);
    }

    sort(lanterns.begin(), lanterns.end());

    double len = 0;
    for (int i = 1; i < n; i++)
    {
        double a = double(lanterns[i] - lanterns[i - 1])/2;
        len = max(len, a);
    }

    double b = double(lanterns[0]);
    double c = double(l - lanterns[n - 1]);

    cout << fixed << setprecision(10) << max(len, max(b, c));
}
