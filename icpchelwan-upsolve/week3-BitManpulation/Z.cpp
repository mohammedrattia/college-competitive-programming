#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

vector<ll> is_prime;
vector<ll> primes;

bool check_prime(ll n)
{
    for (ll e : primes)
    {
        if (e >= n)
            break;
        if (n % e == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    n++;
    while (true)
    {
        if (check_prime(n))
        {
            cout << n << endl;
            return;
        }
        n++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    is_prime = vector<ll>(SZ + 1, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= SZ; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= SZ; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 0; i <= SZ; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
        solve();
}
