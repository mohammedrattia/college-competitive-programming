#include <iostream>

using namespace std;

long long P[1000][1000] = { 0 };

int main()
{
    int num = 1000;
    for (long long i = 0; i < num; i++)
    {
        for (long long j = 0; j < num; j++)
        {
            if (i == 0)
                P[i][j] = 1;
            else if (j == 0)
                P[i][j] = 1;
            else if (P[i-1][j]+P[i][j-1] > 100000 || P[i-1][j] == 0 || P[i][j-1] == 0)
                P[i][j] = 0;
            else
                P[i][j] = P[i-1][j]+P[i][j-1];

        }
    }

    /*for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            cout << P[i][j] << ' ';
        cout << endl;
    }*/

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int m = 0;
        for (int i = 2; i < num; i++)
            for (int j = 2; j < num; j++)
                if (P[i][j] <= n && P[i][j] > 1) m++;
        cout << m + 2*(n-2) + 1 << endl;
    }
}
