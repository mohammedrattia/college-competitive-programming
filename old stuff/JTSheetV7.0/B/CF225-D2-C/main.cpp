#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, x, y;
const int OO = 10000005;
int mem[1005][1005][3];
string grid;
int freq[1005];

int barcode(int idx, int num, int last)
{
    if (idx == m)
    {
        if (num < x || num > y)
            return OO * 10;
        return 0;
    }

    int &ret = mem[idx][num][last];

    if (ret != -1)
        return ret;

    int dots = OO;
    if (idx == 0 || (last == 1 && num >= x) || (last == 0 && num < y))
    {
        dots = (n-freq[idx]) + barcode(idx+1, (last == 0) ? num+1 : 1, 0);
    }
    int hashes = OO;
    if (idx == 0 || (last == 0 && num >= x) || (last == 1 && num < y))
    {
        hashes = freq[idx] + barcode(idx+1, (last == 1) ? num+1 : 1, 1);
    }

    ret = min(dots, hashes);
    return ret;
}

int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> grid;
        for (int j = 0; j < m; j++)
        {
            if (grid[j] == '.')
                freq[j]++;
        }
    }

    memset(mem, -1, sizeof(mem));
    cout << barcode(0, 0, 2);
}
