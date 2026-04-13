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
#define rep(i, a, b)	for(int i = a; i < (int)(b); ++i)
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

ll water[100005];
ll anger[100005];
ll freq[10005];
ll n, x;

ll angerl(int i, int g)
{
    return pow(max(water[i]-g, (ll)0), 2) * anger[i];
}

ll solve(int i, int w)
{
    if (i == n || w == 0)
    {
        return 0;
    }
    int ret;

    ret = 0;
    rep(j, 0, water[i])
    {
        ret = max(angerl(i, j), solve(i+1, max(0, w-j)));
    }
    return ret; //min max anger level
}

int main()
{
    ll t, st;
    cin >> t >> st;
    while (t--)
    {
        cin >> n >> x;
        if (st == 4)
        {
            memset(freq, 0, sizeof(freq));
            rep(i, 0, n)
            {
                cin >> water[i];
                freq[water[i]]++;

            }
            rep(i, 0, n)
            {
                cin >> anger[i];
                if (anger[i] == 0)
                {
                    freq[water[i]]--;
                    water[i] = 0;
                }
            }
            ll w = x;
            ll worse = 0;
            lpd(i, 10001, 1)
            {
                if (freq[i] != 0)
                {
                    worse = i;
                    if (w-freq[i] >= 0)
                    {
                        freq[i-1] += freq[i];
                        w -= freq[i];
                        freq[i] = 0;
                        worse = i-1;
                    }
                }
                if (w-freq[i] < 0)
                {
                    break;
                }
            }
            cout << worse*worse << endl;

        }
        else if (st == 1)
        {
            ll worse = 0;
            rep(i, 0, n)
            {
                worse = max(worse, water[i]*water[i]*anger[i]);
            }
            cout << worse << endl;
        }
        else if (st == 2)
            cout << 0 << endl;
        else
        {
            rep(i, 0, n)
            {
                cin >> water[i];

            }
            rep(i, 0, n)
            {
                cin >> anger[i];
            }
            cout << solve(0, x) << endl;
        }
    }
}
