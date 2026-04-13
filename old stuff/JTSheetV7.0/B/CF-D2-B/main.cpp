#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long waste[1005];

int main()
{
    long long n, m, k, t;
    cin >> n >> m >> k >> t;
    string str[3] = {"Grapes", "Carrots", "Kiwis"};

    long long a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        waste[i] = (a - 1)*m + b;
    }
    sort(waste, waste + k);
    long long test = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        test = (a - 1)*m + b;
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            if (waste[i] == test)
            {
                cout << "Waste" << endl;
                break;
            }
            else if (waste[i] > test)
            {
                cout << str[(test - sum)%3] << endl;
                break;
            }
            else if (i == k-1)
            {
                cout << str[(test - (sum + 1))%3] << endl;
                break;
            }

            sum++;
        }
    }
}
