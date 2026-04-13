#include <bits/stdc++.h>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int dif[1000001][9];

int main()
{
    freopen("lucky.in", "r", stdin);
    int q;
    cin >> q;
    int arr[7];
    memset(arr, -1, sizeof(arr));
    memset(dif, 0, sizeof(dif));
    for (int i = 1; i < 1000001; i++)
    {
        int d = i;
        int k = 0;
        while (d!=0)
        {
            arr[k] = d%10;
            d /= 10;
            k++;
        }
        sort(arr, arr+7, myfunction);
        int mx = 0;
        for (int j = 0; j < 6; j++)
        {
            if(arr[j+1]==-1)
                break;
            mx = max(mx, arr[j]-arr[j+1]);
        }
        for (int j = 0; j < 9; j++)
        {
            if (mx <= j)
                dif[i][j] = dif[i-1][j]+1;
            else dif[i][j] = dif[i-1][j];
        }
    }

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (x>=9)
        {
            cout << r+1-l << endl;
            continue;
        }

        cout << dif[r][x]-dif[l-1][x] << endl;
    }
}
