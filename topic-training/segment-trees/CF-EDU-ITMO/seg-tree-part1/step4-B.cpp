// #pragma GCC optimize("O2")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <climits>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <random>

using namespace std;

// BASIC DEFINES
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

// OTHER DEFINES
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)
#define dbg(x) cout << #x << " = " << x << '\n'
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

// GRID MOVEMENT
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// RANDOMIZATION
mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

// SEGMENT TREE
struct segtype
{
    ll a, b, c, d;
};
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    segtype item;
};
struct Tree
{
    TreeNode *head;
};
class SegTree
{
public:
    const segtype NEUTRAL_CASE = {1, 0, 0, 1};
    Tree tree;
    ll sz, mod;
    segtype (*merge)(segtype a, segtype b, ll r);

    SegTree(vector<segtype> &arr, ll r, segtype (*operation)(segtype a, segtype b, ll r))
    {
        mod = r;
        merge = operation;
        sz = arr.size();
        tree.head = buildTree(&arr, 0, arr.size());
    }

    void set(int i, segtype v)
    {
        setRec(i, v, tree.head, 0, sz);
    }

    segtype get(int l, int r)
    {
        return getRec(l, r, tree.head, 0, sz);
    }

private:
    TreeNode *buildTree(vector<segtype> *arr, int l, int r)
    {
        if (r - l == 1)
        {
            TreeNode *leaf = new TreeNode();
            leaf->item = ((*arr)[l]);
            return leaf;
        }
        int m = (l + r) / 2;
        TreeNode *left = buildTree(arr, l, m);
        TreeNode *right = buildTree(arr, m, r);
        TreeNode *root = newParentNode(left, right);
        return root;
    }

    TreeNode *newParentNode(TreeNode *left, TreeNode *right)
    {
        TreeNode *root = new TreeNode();
        root->left = left;
        root->right = right;
        root->item = merge(left->item, right->item, mod);
        return root;
    }

    segtype getRec(int l, int r, TreeNode *x, int lx, int rx)
    {
        if (l >= rx || lx >= r || x == NULL)
            return NEUTRAL_CASE;
        if (lx >= l && rx <= r)
            return x->item;
        int m = (lx + rx) / 2;
        segtype s1 = getRec(l, r, x->left, lx, m);
        segtype s2 = getRec(l, r, x->right, m, rx);
        return merge(s1, s2, mod);
    }

    void setRec(int i, segtype v, TreeNode *x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            x->item = (v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            setRec(i, v, x->left, lx, m);
        else
            setRec(i, v, x->right, m, rx);
        x->item = merge(x->left->item, x->right->item, mod);
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll r, n, m;
    cin >> r >> n >> m;
    vector<segtype> arr(n);
    ll last = 0;
    rep(i, 0, n) cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
    SegTree st = SegTree(arr, r, [](segtype a, segtype b, ll r) -> segtype
                         { return {
                               ((a.a * b.a) % r + (a.b * b.c) % r) % r,
                               ((a.a * b.b) % r + (a.b * b.d) % r) % r,
                               ((a.c * b.a) % r + (a.d * b.c) % r) % r,
                               ((a.c * b.b) % r + (a.d * b.d) % r) % r}; });

    rep(i, 0, m)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        segtype v = st.get(l, r);
        cout << v.a << ' ' << v.b << endl
             << v.c << ' ' << v.d << endl
             << endl;
    }
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
