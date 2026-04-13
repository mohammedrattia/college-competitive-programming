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
        string str;
        cin >> str;
        string name = "Timur";
        sort(name.begin(), name.end());
        sort(str.begin(), str.end());
        if (n!=5)
            cout << "No" << endl;
        else
        {
            int num = 0;
            cout << ((str == name) ? "YES" : "NO") << endl;
        }
    }
}
