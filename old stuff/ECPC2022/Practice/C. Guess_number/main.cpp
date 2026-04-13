#include <iostream>

using namespace std;

int main()
{
    char c = '2';
    int s = 0, e = 1000000000;
    int x;
    while (s <= e)
    {
        x = (s + e)/2;
        printf("%d\n", x);
        fflush(stdout);
        scanf(" %c", &c);
        if (c == '<')
            e = x-1;
        else if (c == '>')
            s = x+1;
        else
        {
            printf("! %d\n", x);
            fflush(stdout);
            break;
        }
    }
}
