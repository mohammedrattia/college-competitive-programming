#include <iostream>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    set<double> s;
    double a, b;
    int v = 0;
    rep(i, 0, n)
    {
        cin >> a >> b;
        if ((int)(a-x) == 0)
            v = 1;
        else
        {
            s.insert((b-y)/(a-x));
        }
    }
    cout << s.size() + v;
}
