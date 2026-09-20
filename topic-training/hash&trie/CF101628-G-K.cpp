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

// TRIE
struct Node
{
    int cnt;
    int leaf;
    ordered_set<int> cidx;
    ordered_set<int> lidx;
    Node *ptr[26];
};
struct Trie
{
    Node *root;
    Trie() { root = new Node(); }
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
            cur->cidx.insert(x);
        }
        cur->lidx.insert(x);
        cur->leaf++;
    }
    void erase(string &s, int x)
    {
        Node *cur = root;
        for (auto &i : s)
        {
            int rank = i - 'a';
            if (cur->ptr[rank] == NULL)
                cur->ptr[rank] = new Node();
            cur = cur->ptr[rank];
            cur->cnt--;
            cur->cidx.erase(x);
        }
        cur->lidx.erase(x);
        cur->leaf--;
    }
    bool vprefix(string &s, int l, int r)
    {
        Node *cur = root;
        for (auto &i : s)
        {
            int rank = i - 'a';
            if (cur->ptr[rank] == NULL)
                return false;
            cur = cur->ptr[rank];
            if (cur->leaf)
            {
                int lower = cur->lidx.order_of_key(l);
                int upper = cur->lidx.order_of_key(r);
                if (upper != lower)
                    return true;
            }
        }
        return false;
    }
    bool sprefix(string &s, int l, int r)
    {
        Node *cur = root;
        for (auto &i : s)
        {
            int rank = i - 'a';
            if (cur->ptr[rank] == NULL)
                return false;
            cur = cur->ptr[rank];
        }
        if (cur->cnt)
        {
            int lower = cur->cidx.order_of_key(l);
            int upper = cur->cidx.order_of_key(r);
            if (upper != lower)
                return true;
        }
        return false;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> arr(n);
    Trie trie = Trie();
    rep(i, 0, n)
    {
        cin >> arr[i];
        trie.insert(arr[i], i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            int i;
            string s;
            cin >> i >> s;
            i--;
            trie.erase(arr[i], i);
            arr[i] = s;
            trie.insert(arr[i], i);
            break;
        }
        case 2:
        {
            int l, r;
            string s;
            cin >> l >> r >> s;
            l--;
            cout << (trie.vprefix(s, l, r) ? "Y" : "N") << endl;
            break;
        }
        case 3:
        {
            int l, r;
            string s;
            cin >> l >> r >> s;
            l--;
            cout << (trie.sprefix(s, l, r) ? "Y" : "N") << endl;
            break;
        }
        }
    }
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
