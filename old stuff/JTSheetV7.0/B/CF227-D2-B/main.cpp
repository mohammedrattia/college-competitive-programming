#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    map<long long, long long> nums;
    long long a;
    for (long long i = 0; i < n; i++)
    {
        cin >> a;
        nums[a] = i + 1;
    }

    long long m;
    cin >> m;
    long long b, sumV = 0, sumP = 0;
    for (long long i = 0; i < m; i++)
    {
        cin >> b;
        sumV += nums[b];
        sumP += n - nums[b] + 1;
    }
    cout << sumV << " " << sumP;
}
