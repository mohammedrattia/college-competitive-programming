#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[(int)log2(n)+1][n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
    }

    for (int k = 2; k <= n; k<<1)
    {
        for (int i = 0; i+k-1 < n; i++)
        {
            arr[(int)log2(k)][i] = min(arr[(int)log2(k)-1][i], arr[(int)log2(k)-1][i+k/2]);
        }
    }

    /*for (int k = 1; k <= n; k*=2)
    {
        for (int i = 0; i+k-1 < n; i++)
        {
            cout << arr[(int)log2(k)][i] << ' ';
        }
        cout << endl;
    }*/
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << arr[(int)log2(b-a+1)][a-1] << ' ';
        cout << arr[(int)log2(b-a+1)][b-(int)pow(2,(int)log2(b-a+1))] << endl;
    }
}
