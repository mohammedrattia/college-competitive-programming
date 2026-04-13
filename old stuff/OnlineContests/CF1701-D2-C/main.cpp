#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a;
        vector<int> freq(n, 0);

        for (int i = 0; i < m; i++)
        {
            cin >> a;
            freq[a-1]++;
        }

    }
}
