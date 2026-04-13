#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    int num = ((max(x1, x2)-min(x1, x2))+(max(y1, y2)-min(y1, y2)))*2;
    pair<double, double> idx[num];
    int k = 0;
    for (double i = min(x1, x2); i <= max(x1, x2); i++)
    {
        if (i == x1 || i == x2)
        {
            for (double j = min(y1, y2); j <= max(y1, y2); j++)
            {
                idx[k++] = make_pair(i, j);
            }
        }
        else
        {
            idx[k++] = make_pair(i, y1);
            idx[k++] = make_pair(i, y2);
        }
    }
    double x[n], y[n], r[n];
    double p = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (k = 0; k < num; k++)
    {
        bool b = 1;
        for (int i = 0; i < n; i++)
        {
            double d = sqrt(pow(x[i]-idx[k].first, 2)+pow(y[i]-idx[k].second, 2));
            if (d <= r[i])
            {
                b = 0;
            }
        }
        if (b)
            p++;
        b = 1;
    }
    cout << p;
}
