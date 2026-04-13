#include <iostream>

using namespace std;

string s, t;
bool valid(int i, int a)
{
    return i < a && i >= 0;
}
bool b = 1;
int dfs(int i, int cur = 0, int last = 1)
{
    if (!valid(i, s.size()) || !valid(cur, t.size()))
        return 0;

    if (s[i] != t[cur])
        return 0;
    if (cur == t.size()-1)
    {
        cout << "YES" << endl;
        b = 0;
        return 0;
    }
    if (last && b)
    {
        dfs(i+1, cur+1, 1);
    }
    if (b)
        dfs(i-1, cur+1, 0);
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        b = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[0])
            {
                dfs(i);
            }
            if (!b)
                break;
        }
        if (b)
            cout << "NO" << endl;
    }
}
