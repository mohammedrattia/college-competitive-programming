// #pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>> using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

// BASIC DEFINES
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

// OTHER DEFINES
#define PI 3.14159265358979323846
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)
#define dbg(x) cout << #x << " = " << x << '\n'
#define FAST                                                                                       \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

// STRING HASHING
const int N = 1e6 + 5, P1 = 31, P2 = 37, M = 1e9 + 7;
int pw1[N], pw2[N], inv1[N], inv2[N];
int mul(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a * 1LL * b) % M;
}
int add(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a + b) % M;
}
int fastPower(int base, int power)
{
    if (!power)
        return 1;
    int ret = fastPower(base, power >> 1);
    ret = mul(ret, ret);
    if (power % 2)
        ret = mul(ret, base);
    return ret;
}
void pre()
{
    pw1[0] = inv1[0] = pw2[0] = inv2[0] = 1;
    int mulInv1 = fastPower(P1, M - 2);
    int mulInv2 = fastPower(P2, M - 2);
    for (int i = 1; i < N; i++)
    {
        pw1[i] = mul(pw1[i - 1], P1);
        pw2[i] = mul(pw2[i - 1], P2);
        inv1[i] = mul(inv1[i - 1], mulInv1);
        inv2[i] = mul(inv2[i - 1], mulInv2);
    }
}
struct Hash
{
    vector<pair<int, int>> prefixHash;
    Hash(string s)
    {
        prefixHash = vector<pair<int, int>>(s.size(), {0, 0});
        for (int i = 0; i < (int)s.size(); i++)
        {
            prefixHash[i].F = mul(s[i] - 'a' + 1, pw1[i]);
            prefixHash[i].S = mul(s[i] - 'a' + 1, pw2[i]);
            if (i)
                prefixHash[i] = {add(prefixHash[i].F, prefixHash[i - 1].F),
                                 add(prefixHash[i].S, prefixHash[i - 1].S)};
        }
    }
    pair<int, int> getHashVal() { return prefixHash.back(); }
    pair<int, int> getRangeHashVal(int l, int r)
    {
        return {mul(add(prefixHash[r].F, -(l ? prefixHash[l - 1].F : 0)), inv1[l]),
                mul(add(prefixHash[r].S, -(l ? prefixHash[l - 1].S : 0)), inv2[l])};
    }
};
ll pair_hash(pair<int, int> a) { return ((ll)a.F << 32ll) + (ll)a.S; }

deque<int> ans;

// TRIE
struct Node
{
    int cnt;
    int leaf;
    int idx;
    Node *ptr[26];
};
struct Trie
{
    Node *root;
    string str;
    int size;
    Trie(string &str, int n)
    {
        root = new Node();
        this->str = str;
        size = n;
    }
    void insert(string &s, int x)
    {
        Node *cur = root;
        for (auto &i : s)
        {
            int rank = i - 'a';
            if (cur->ptr[rank] == NULL)
                cur->ptr[rank] = new Node();
            cur = cur->ptr[rank];
            cur->cnt++;
        }
        cur->leaf = 1;
        cur->idx = x;
    }
    int search(int idx = 0)
    {
        if (idx == size)
            return 1;
        Node *cur = root;
        while (idx < size)
        {
            int rank = str[idx] - 'a';
            if (cur->ptr[rank] == NULL)
                return 0;
            cur = cur->ptr[rank];
            idx++;
            if (cur->leaf)
            {
                ans.push_back(cur->idx);
                if (search(idx))
                    return cur->leaf;
                else
                    ans.pop_back();
            }
        }
        return cur->leaf;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n;
    string str;
    cin >> n >> str;
    Trie trie = Trie(str, n);
    int m;
    cin >> m;
    vector<string> arr(m);
    rep(i, 0, m)
    {
        cin >> arr[i];
        string temp = arr[i];
        rep(j, 0, (int)arr[i].size()) { temp[arr[i].size() - j - 1] = (char)tolower(arr[i][j]); }
        trie.insert(temp, i);
    }
    trie.search();

    for (auto &e : ans)
        cout << arr[e] << ' ';
    cout << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while
    solve();
}
