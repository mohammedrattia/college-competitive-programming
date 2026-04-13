#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mem[5001][5001];

string str;
int n;
vector<int> idx;

int solve(int s, int e)
{
    if (s < 0 || e >= idx.size() || s > e)
        return 0;

    int &ret = mem[idx[s]][idx[e]];

    if (ret != -1)
        return ret;

    ret = (((e-s+1)%2 == 0) ? -1 : 1)*(n-(idx[e]+3))*(idx[s]+1);
    if (s >= 0 && e+1 < idx.size() && (e+1)-s <= 1 && (e+1)-s >= 0)
        ret += solve(s, e+1);
    if (s+1 >= 0 && e < idx.size() && e-s-1 <= 1 && e-s-1 >= 0)
        ret += solve(s+1, e);

    return ret;
}

int main()
{
    cin >> str;

    memset(mem, -1, sizeof(mem));
    n = str.size();

    for (int i = 0; i < str.size(); i++)
    {
        if (str.substr(i, 4) == "bear")
        {
            idx.push_back(i);
        }
    }

    cout << solve(0, 0);
}
