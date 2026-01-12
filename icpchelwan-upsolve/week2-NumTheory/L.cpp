#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int rem = n;

    vector<ll> primes;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.push_back(n);

    if (primes.size() < k)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < k - 1; i++)
    {
        rem /= primes[i];
        cout << primes[i] << ' ';
    }
    cout << rem;
}
