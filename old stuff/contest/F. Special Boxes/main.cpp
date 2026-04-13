#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int box = 1, cnt = 1;
    vector<int> balls(n, 1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x = box)
        {
            box = y;
        }
    }
}
