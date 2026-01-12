#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

vector<pair<int, int>> v;

void tower(int n, int l = 1, int mid = 2, int r = 3)
{
    if (n == 1)
    {
        v.push_back({l, r});
        return;
    }

    tower(n - 1, l, r, mid);
    v.push_back({l, r});
    tower(n - 1, mid, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    tower(n);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << endl;
}
