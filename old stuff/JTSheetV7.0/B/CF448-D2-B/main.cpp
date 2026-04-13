#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int l = 26;
int cnt[l];

int main()
{
    cin.tie();
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i)
    {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < t.size(); ++i)
    {
        --cnt[t[i] - 'a'];
    }
    bool aut = true, arr = true, b = true;
    for (int i = 0; i < l; ++i)
    {
        b = b && cnt[i] >= 0;
        arr = arr && cnt[i] == 0;
    }
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (j < t.size() && t[j]==s[i])
            ++j;
    }
    aut = j == t.size();
    string ans;
    if (aut)
        ans = "automaton";
    else if (arr)
        ans = "array";
    else if (b)
        ans = "both";
    else ans = "need tree";

    cout << ans;
}
