#include <iostream>
#include <cstring>

using namespace std;

long long x[100005];
long long h[100005];
long long n;
long long mem[100005][3];

long long trees(long long i, long long last)
{
    if (i == n)
        return 0;

    long long &ret = mem[i][last];

    if (ret != -1)
        return ret;

    ret = 0;

    if (i == n-1 || x[i] + h[i] < x[i+1])
        ret = max(ret, 1+trees(i+1, 1));

    if (i == 0 || x[i] - h[i] > x[i-1] + ((last==1)*h[i-1]))
        ret = max(ret, 1+trees(i+1, 0));

    ret = max(ret, trees(i+1, 2));
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> h[i];

    if (n <= 2)
    {
        cout << n;
        return 0;
    }
    memset(mem, -1, sizeof(mem));
    cout << trees(0, 2);
}
