#include <iostream>

using namespace std;

int arr[2*100000+5];
int n, s;
int INF = 2*100000+5;

int dfs(int sum, int steps = 0, int fr = 0, int bk = n-1)
{
    if (fr == bk || sum < s)
        return INF;
    if (sum == s)
        return steps;
    return min(dfs(sum-arr[fr], ++steps, ++fr, bk), dfs(sum-arr[bk], ++steps, fr, --bk));

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << dfs(sum) << endl;
    }
}
