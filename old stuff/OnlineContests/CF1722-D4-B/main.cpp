#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define push_back pb

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;
        bool b = 1;
        rep(i, 0, n)
        {
            if (row1[i] == 'G')
                row1[i] = 'B';
            if (row2[i] == 'G')
                row2[i] = 'B';

            if (row1[i] != row2[i])
            {
                b = 0;
                break;
            }
        }
        if (b)
            cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
