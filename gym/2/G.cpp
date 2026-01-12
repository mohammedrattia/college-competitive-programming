#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

string toBinary(ll num)
{
    if (num == 0)
        return "0";
    string res;
    while (num)
    {
        res += (num % 2) + '0';
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
string addBinary(string A, string B)
{
    if (A.length() > B.length())
        return addBinary(B, A);

    int diff = B.length() - A.length();
    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');

    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
        if (A[i] == '1' && B[i] == '1')
        {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }

        else if (A[i] == '0' && B[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }

        else if (A[i] != B[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }

    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end());

    int index = 0;
    while (index + 1 < res.length() &&
           res[index] == '0')
        index++;
    return (res.substr(index));
}

string multiplyBinary(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if (s1 == "0" || s2 == "0")
        return "0";

    vector<int> result(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; i--)
    {
        int bit1 = s1[i] - '0';
        for (int j = n2 - 1; j >= 0; j--)
        {
            int bit2 = s2[j] - '0';
            result[i + j + 1] += bit1 * bit2;
        }
    }

    // Handle carries
    for (int i = result.size() - 1; i > 0; i--)
    {
        if (result[i] >= 2)
        {
            result[i - 1] += result[i] / 2;
            result[i] %= 2;
        }
    }

    // Convert to string, skipping leading zeros
    string product = "";
    int i = 0;
    while (i < result.size() && result[i] == 0)
        i++;

    while (i < result.size())
        product += result[i++] + '0';

    return product.empty() ? "0" : product;
}

vll arr;
void solve()
{
    string str;
    cin >> str;
    ll n = str.size();
    string ans = "0";
    rep(i, 0, n)
    {
        if (str[i] == '0')
            continue;
        string temp(n - i, '1');
        temp = multiplyBinary(temp, toBinary(i + 1));
        ans = addBinary(ans, temp);
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}