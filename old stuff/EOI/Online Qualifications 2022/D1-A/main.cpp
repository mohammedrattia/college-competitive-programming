#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define lp(i, v)		for(int i=0;i<sz(v);++i)
#define rep(i, a, b)		for(int i=a; i < (int)(b); ++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const int OO = (int)1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;


int main()
{
    int t, st;
    cin >> t >> st;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int cnt = 0;
        bool b = 1;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '?')
            {
                if (i == 0)
                {
                    while (i < n && str[i] == '?')
                        idx = i++;
                    continue;
                }
                cnt = 0;
                while (i < n && str[i] == '?')
                {
                    str[i] = '0' + !(bool)(str[i-1] - '0');
                    i++;
                    cnt++;
                }
                if (i == n) continue;
                if (str[i] == str[i-1])
                {
                    b = 0;
                    break;
                }
            }
            else if (i > 0 && str[i] == str[i-1])
            {
                b = 0;
                break;
            }
        }
        if (b)
        {
            if (str[0] == '?')
            {
                while (idx >= 0)
                {
                    str[idx] = '0' + !(bool)(str[idx+1] - '0');
                    idx--;
                }
            }
            cout << str << endl;
        }
        else cout << "Impossible" << endl;
    }
}
/*
3
0?1
*/
