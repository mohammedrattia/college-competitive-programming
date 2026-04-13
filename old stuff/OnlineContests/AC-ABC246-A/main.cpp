#include <iostream>

using namespace std;

int main()
{
    int x[3], y[3], k, j;
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    if (x[0] == x[1])
        k = x[2];
    else if (x[1] == x[2])
        k = x[0];
    else
        k = x[1];

    if (y[0] == y[1])
        j = y[2];
    else if (y[1] == y[2])
        j = y[0];
    else
        j = y[1];
    cout << k << " " << j;
}
