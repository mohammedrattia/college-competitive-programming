#include <stdio.h>

void solve()
{
    int l = 0, r = 1e9+1;
    char c;
    while (l <= r)
    {
        int mid = l + (r-l+1)/2;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("\n%c", &c);
        if (c == '>') l = mid + 1;
        else if (c == '<') r = mid - 1;
        else
        {
            printf("! %d", mid);
            return;
        }
    }
}

int main()
{
    solve();
}

