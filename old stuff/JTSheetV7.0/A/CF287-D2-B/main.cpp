#include <iostream>

using namespace std;

long long n, k, sumk;

long long sum(long long k)
{
    if (k % 2 == 0)
        return 1 + (k/2)*(k - 1);
    else
        return 1 + ((k - 1)/2)*(k - 2)+(k-1);
}

long long b_search(long long startn, long long endn)
{
    while (startn < endn)
    {
        long long mid = (endn + startn)/2;
        if (n < sumk - sum(mid))
        {
            if (n > sumk - sum(mid+1))
                return k - mid;
            startn = mid + 1;
        }
        else if (n > sumk - sum(mid))
        {
            if (n < sumk - sum(mid-1))
                return k - (mid-1);
            endn = mid - 1;
        }
        else return k - mid - 1;
    }
    return k - startn;
}

int main()
{
    cin >> n >> k;
    sumk = sum(k);
    if (n == 1) cout << 0;
    else if (n <= k) cout << 1;
    else
    {
        if (n > sumk) cout << -1;
        else
        {
            cout << b_search(1, k-1);
        }
    }
}
