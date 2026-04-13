#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int arr[n];
    int gmx = -1, gmn = -1, hmn = -1, hmx = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (str[i-1]=='G')
            gmx=i;
        else if (str[i-1]=='H')
            hmx=i;
        if (str[i-1]=='G' && gmn==-1)
            gmn=i;
        else if (str[i-1]=='H' && hmn==-1)
            hmn=i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int cnt = 0, l;
    if (arr[gmn-1]>=gmx && arr[hmn-1]>=hmx)
    {
        cnt++;
        l = max(hmn, gmn);
    }
    else if (arr[gmn-1]>=gmx)
    {
        l = gmn;
    }
    else if  (arr[hmn-1]>=hmx)
    {
        l = hmn;
    }

    for (int i = 1; i < l; ++i)
    {
        if (str[i-1]!=str[l-1] && arr[i-1]>=l)
            cnt++;
    }
    cout << cnt;
}
