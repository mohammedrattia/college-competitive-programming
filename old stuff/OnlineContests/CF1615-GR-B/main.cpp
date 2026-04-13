#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int min_num = 0;
        for (int p = 1; p < pow(2,20); p * 2)
        {
            int sec_num_r = r/p + (r % p != 0);
            int zero_sec_r = sec_num_r + (sec_num_r % 2);
            int zeros_r = zero_sec_r * p;
            int real_zeros_r = zeros_r + ((r + 1) % p);

            int sec_num_l = l/p + (l % p != 0);
            int zero_sec_l = sec_num_l + (sec_num_l % 2);
            int zeros_l = zero_sec_l * p;
            int real_zeros_l = zeros_l + ((r + 1) % p);

            int num = real_zeros_r - real_zeros_l;
            if (num < min_num)
                min_num = num;
        }
        cout << min_num << endl;
    }
}
