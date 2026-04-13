#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<string, int> b;
        string x;
        int y;
        string ans = "OK";
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            if (b.count(x) && b[x] != y)
                ans = "LIE";
            b[x] = y;
        }
        if (n == 2)
        {
            if (b["00"] == b["11"] && b["01"] == b["10"])
                ans = "LIE";
            if (b["00"] == b["11"] && b["01"] != )
            {
                ans = "LIE";
            }
        }
        cout << ans << endl;
    }
}
