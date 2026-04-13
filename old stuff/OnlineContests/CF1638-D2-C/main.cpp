//TLE
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> p;
vector<int> a;
vector<bool> visited;

void dfs (int node)
{
    if (visited[node])
        return;

    visited[node] = 1;

    for (auto child : p[node])
        dfs(child);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        p = vector<vector<int>>(n);
        visited = vector<bool>(n, 0);
        a.reserve(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            int x = i + 1;
            while (x < n)
            {
                if (a[i] > a[x])
                {
                    p[a[i] - 1].push_back(a[x] - 1);
                    p[a[x] - 1].push_back(a[i] - 1);
                }
                x++;
            }
        }
        int comp = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                comp++;
                dfs(i);
            }
        }
        cout << comp << endl;
    }
}
