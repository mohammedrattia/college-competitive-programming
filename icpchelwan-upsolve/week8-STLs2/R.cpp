#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n, s;
    cin >> n >> s;
    map<int, int, greater<>> sell, buy;
    for (int i = 0; i < n; i++)
    {
        char d;
        int p, q;
        cin >> d >> p >> q;
        if (d == 'B')
            buy[p] += q;
        else
            sell[p] += q;
    }
    int i = 0, cntS = sell.size();
    for (auto e : sell)
    {
        if (i >= cntS - s)
            cout << "S " << e.first << ' ' << e.second << endl;
        i++;
    }
    i = 0;
    for (auto e : buy)
    {
        if (i < s)
            cout << "B " << e.first << ' ' << e.second << endl;
        i++;
    }
}