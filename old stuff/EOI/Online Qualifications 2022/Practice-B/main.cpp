#include <iostream>
#include "guessx.h"

using namespace std;

int guess_number(int n)
{
    int a = 0, b = n;
    while (a<=b)
    {
        int c = (a+b)/2;
        if (isLessThanX(c))
        {
            b = c-1;
        }
        else a = c;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        cout << guess_number(n);
    }
}
