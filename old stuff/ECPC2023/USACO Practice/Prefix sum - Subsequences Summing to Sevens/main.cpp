#include <iostream>
#include <vector>

using namespace std;

void setIO(string s)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    //setIO("div7");
    long long n;
    cin >> n;
    vector<long long> arr(7, -1);
    arr[0] = 0;
    long long x, mx = 0, cur = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> x;

        cur = (cur+x)%7;
        if (arr[cur] == -1)
            arr[cur] = i;
        else mx = max(mx, i-arr[cur]);
    }
    cout << mx;
}
