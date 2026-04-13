#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans = max(x, ans);
    }
    cout << ans;
}
