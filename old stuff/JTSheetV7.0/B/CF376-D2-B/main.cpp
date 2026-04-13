#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj(n+1, {0, 0});
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].first += c;
        adj[b].second += c;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += max(0, adj[i].first-adj[i].second);
    }
    cout << sum;
}
