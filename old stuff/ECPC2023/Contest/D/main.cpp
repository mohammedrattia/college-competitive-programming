#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    bool visited[n] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[arr[i-1]-1] == i && !visited[i-1])
        {
            visited[arr[i-1]-1] = 1;
            cnt++;
        }
    }
    cout << cnt;
}
