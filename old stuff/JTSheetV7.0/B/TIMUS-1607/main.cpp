#include <iostream>

using namespace std;

int main()
{
    int ip, rp, id, rd;
    cin >> ip >> rp >> id >> rd;

    int rat = (id - ip)/(rd + rp);
    int x = ip + (rat + 1) * rp, y = id - rat * rd;

    cout << (x > y ? y : x);
}
