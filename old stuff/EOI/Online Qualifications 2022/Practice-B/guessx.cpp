#include <bits/stdc++.h>
#include "guessx.h"

// You don't need to change anything in includes,
// you can submit your code as it is.

#ifndef ONLINE_JUDGE
#include "grader.cpp"
#endif

int guess_number(int n)
{
    int a = 1, b = n;
    int c = 0;
    while (a < b)
    {
        c = a + (b-a)/2;
        //std::cout << a << " " << c << " " << b << std::endl;
        assert(c<b);
        if (isLessThanX(c))
            a = c+1;
        else b = c;
    }
    c = a + (b-a)/2;

    return c;
}
