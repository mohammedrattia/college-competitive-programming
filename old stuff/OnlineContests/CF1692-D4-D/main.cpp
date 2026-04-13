#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hrs, mins, x;
        char c;
        scanf("%d%c%d %d", &hrs, &c, &mins, &x);

        //cout << hrs << " " << mins;
        int d_hrs = x/60, d_mins = x%60;
        int num = 0;
        int cur_hrs = hrs, cur_mins = mins;

        while (true)
        {
            if (cur_hrs/10 == cur_mins%10 && cur_hrs%10 == cur_mins/10)
                num++;
            cur_mins += d_mins;
            cur_hrs += d_hrs + (cur_mins / 60);
            cur_mins %= 60;
            cur_hrs %= 24;
            if (cur_hrs == hrs && cur_mins == mins)
                break;
        }
        cout << num << endl;
    }
}
