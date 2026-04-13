#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int m, OO = 1000000;
int mem[1000000];

int solve(int n, int num = 0)
{
    if (n == m)
        return 0;
    if (n < 0)
        return OO;

    int &ret = mem[n];
    if (ret != -1)
        return ret;
    ret = OO;
    if (n < m)
        ret = min(ret, solve(n*2, num+1)+1);
    ret = min(ret, solve(n-1, num+1)+1);
    return ret;
}
int main()
{
    int n;
    cin >> n >> m;
    memset(mem, -1, sizeof(mem));
    cout << solve(n);
}
