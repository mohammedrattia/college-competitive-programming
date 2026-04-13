#include <iostream>

using namespace std;

int arr[1005][1005];
int n, m;

void dfs(string &ans, int sum, int i = 0, int j = 0)
{
    if (i == n-1 && j == m-1)
        if (sum == 0)
            ans = "YES";
    if (i != n-1)
        dfs(ans, sum+arr[i+1][j], i+1, j);
    if (j != m-1)
        dfs(ans, sum+arr[i][j+1], i, j+1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        string ans = "NO";
        dfs(ans, arr[0][0]);
        cout << ans << endl;
    }
}
