#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp (pair<int, int> i, pair<int, int> j)
{
    return abs(i.second - i.first) < abs(j.second - j.first);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        if (!k)
        {
            cout << n << '\n' << str << endl;
            continue;
        }
        vector<int> g, h;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == 'G')
                g.push_back(i);
            else if (str[i] == 'H')
                h.push_back(i);
        }
        int a = 0, b = 0;
        vector<pair<int, int>> idxg;
        while (b < g.size())
        {
            if (b+1 == g.size() || g[b+1] - g[a] > k*2)
            {
                idxg.push_back({g[a]+k, (g[b]-k >= 0 ? g[b]-k : 0)});
                //cout << idxg.front().first << ' ' << idxg.back().second << endl;
                b++;
                a = b;
            }
            else
            {
                b++;
            }
        }
        vector<pair<int, int>> idxh;
        b = 0, a = 0;
        while (b < h.size())
        {
            if (b+1 == h.size() || h[b+1] - h[a] > k*2)
            {
                idxh.push_back({h[a]+k, h[b]-k >= 0 ? h[b]-k : 0});
                //cout << idxh.front().first << ' ' << idxh.back().second << endl;
                b++;
                a = b;
            }
            else
            {
                b++;
            }
        }
        string ans(n, '.');

        sort(idxg.begin(), idxg.end(), comp);
        sort(idxh.begin(), idxh.end(), comp);

        int l;
        for (int i = 0; i < idxg.size(); ++i)
        {
            l = 0;
            while (true)
            {
                if (ans[min(idxg[i].first, idxg[i].second)+l] == '.')
                    break;
                l++;
            }
            ans[min(idxg[i].first, idxg[i].second)+l] = 'G';
        }
        for (int i = 0; i < idxh.size(); ++i)
        {
            l = 0;
            while (true)
            {
                if (ans[min(idxh[i].first, idxh[i].second)+l] == '.')
                    break;
                l++;
            }
            ans[min(idxh[i].first, idxh[i].second)+l] = 'H';
        }
        cout << (int)(idxg.size()+idxh.size()) << '\n' << ans << endl;
    }
}
