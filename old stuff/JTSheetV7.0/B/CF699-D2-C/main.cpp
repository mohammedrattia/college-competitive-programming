#include <iostream>
#include <cstring>

using namespace std;

int a[101];
int mem[101][4];
int OO = 100000;
int n;

int hols(int i, int last)
{
    if (i == n)
        return 0;
    int &ret = mem[i][last];

    if (ret != -1)
        return ret;
    ret = OO;

    if (last != 1 && (a[i] == 2 || a[i] == 3))
        ret = min(ret, hols(i+1, 1));
    if (last != 2 && (a[i] == 1 || a[i] == 3))
        ret = min(ret, hols(i+1, 2));
    if (a[i] == 0 || a[i] == 1 || a[i] == 2)
        ret = min(ret, 1+hols(i+1, 0));
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(mem, -1, sizeof(mem));
    cout << hols(0, 3);
}
