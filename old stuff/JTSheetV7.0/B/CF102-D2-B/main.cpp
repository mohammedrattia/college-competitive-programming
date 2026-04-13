#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int cnt = 0;

    while ((int)(n.size()) != 1)
    {
        cnt++;
        int sum = 0;
        for (int i = 0; i < (int)(n.size()); i++)
            sum += n[i] - '0';
        n = to_string(sum);
    }
    cout << cnt;
}
