#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "1\n1 1";
        return 0;
    }
    else
        cout << "0\n" << n - 1;


}
