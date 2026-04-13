#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> arr(200005);
vector<bool> visited(200005);
vector<vector<int>> adj;

int dfs(int node)
{
    if (visited[node])
        return 1;

    visited[node] = 1;

    int h = 1;
    for (auto e : adj[node])
    {
        if (!visited[e])
            h = max(h, dfs(e)+1);
    }
    return h;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        adj = vector<vector<int>>(200005);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0)
                    adj[arr[i]].push_back(arr[j]);
            }
        }
        /*for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ": ";
            for (int j = 0; j < (int) adj[arr[i]].size(); j++)
            {
                cout << adj[arr[i]][j] << ' ';
            }
            cout << endl;
        }*/

        int m = 0;
        for (int i = 0; i < n; i++)
        {
            visited = vector<bool>(200005, 0);
            if (!visited[arr[i]])
                m = max(m, dfs(arr[i]));
        }
        cout << m << endl;
    }
}
