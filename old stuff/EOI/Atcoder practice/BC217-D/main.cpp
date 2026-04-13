#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int l, q;
    std::cin >> l >> q;
    std::set<int> cuts;

    cuts.insert(0);
    cuts.insert(l);
    for (int i = 0; i < q; i++)
    {
        int c, x;
        std::cin >> c >> x;

        if (c == 1)
            cuts.insert(x);
        else
        {
            std::set<int>::iterator it = cuts.lower_bound(x);
            int r = *it, l = *--it;
            std::cout << r - l << std::endl;
        }
    }
    return 0;
}
