#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
const int OO = 1000000000;
int s[21], t[21], c[21], a[11], b[11], p[11], mi[11], arr[105];
int mem[11];
int backtrack(int i = 0, int ct = 0)
{
    if (i == m)
    {
        for (int k = 0; k < n; ++k)
        {
            for (int j = s[k]-1; j <= t[k]-1; ++j)
            {
                if (arr[j]<c[k])
                    return OO;
            }
        }

        return ct;
    }
    /*int &ret = mem[i];
    if (ret!=-1)
        return ret;
    */
    int ret=OO;
    ret = min (ret, backtrack(i+1, ct));
    for (int j = a[i]-1; j <= b[i]-1; ++j)
        arr[j] += p[i];
    ret = min (ret, backtrack(i+1, ct+mi[i]));
    for (int j = a[i]-1; j <= b[i]-1; ++j)
        arr[j] -= p[i];

    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> t[i] >> c[i];
    for (int i = 0; i < m; ++i)
        cin >> a[i] >> b[i] >> p[i] >> mi[i];
    memset(mem, -1, sizeof(mem));
    cout << backtrack();
}
