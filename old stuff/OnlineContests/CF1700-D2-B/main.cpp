#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char l[100005], c;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            scanf("%c", &c);
            l[i] = c;
        }
        if (l[1] == '9')
        {
            int carry = 0;
            int cur = 1;
            for (int i = n; i > 0; i++)
            {
                int num = (int)(l[i]-'0');
                if (cur-num < 0)
                {
                    cur += 10;
                    ans = cur - num;
                    if (ans > 9)
                        ans
                    cout << cur - num;
                    cur =
                }

            }
        }
        else
        {

        }
    }
}
