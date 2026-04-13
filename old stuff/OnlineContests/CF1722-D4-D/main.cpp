#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        ll value = 0;
        rep (i, 0, n)
        {
            if (str[i] == 'L')
                value += i;
            else value += n-i-1;
        }
        vector<long long> arr;
        rep (i, 0, n/2)
        {
            if (str[i] == 'L')
            {
                arr.push_back(value + n-i-1 - i);
                value += n-i-1 - i;
            }
            if (str[n-i-1] == 'R')
            {
                arr.push_back(value - i + n-i-1);
                value += n-i-1 - i;
            }
        }
        rep(i, 0, n)
        {
            cout << ((i<arr.size()) ? arr[i] : value) << " ";
        }
        cout << endl;
    }
}
