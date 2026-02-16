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
typedef ll segtype;
const segtype NEUTRAL_CASE = 0;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    segtype value;

    TreeNode()
    {
        left = NULL;
        right = NULL;
        value = 0;
    }
};
class Tree
{
public:
    TreeNode *head;
    Tree()
    {
        head = NULL;
    }
};
class SegTree
{
public:
    Tree tree;
    ll sz;
    segtype (*func)(segtype a, segtype b);

    SegTree(vector<segtype> &arr, segtype (*operation)(segtype a, segtype b))
    {
        func = operation;
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
            leaf->value = (*arr)[l];
            return leaf;
        }
        int m = (l + r) / 2;
        TreeNode *left = buildTree(arr, l, m);
        TreeNode *right = buildTree(arr, m, r);
        TreeNode *root = merge(left, right);
        return root;
    }

    TreeNode *merge(TreeNode *left, TreeNode *right)
    {
        TreeNode *root = new TreeNode();
        root->left = left;
        root->right = right;
        root->value = op(left, right);
        return root;
    }

    segtype getRec(int l, int r, TreeNode *x, int lx, int rx)
    {
        if (l >= rx || lx >= r || x == NULL)
            return NEUTRAL_CASE;
        if (lx >= l && rx <= r)
            return x->value;
        int m = (lx + rx) / 2;
        segtype s1 = getRec(l, r, x->left, lx, m);
        segtype s2 = getRec(l, r, x->right, m, rx);
        return (*func)(s1, s2);
    }

    void setRec(int i, segtype v, TreeNode *x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            x->value = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            setRec(i, v, x->left, lx, m);
        else
            setRec(i, v, x->right, m, rx);
        x->value = op(x->left, x->right);
    }

    segtype op(TreeNode *left, TreeNode *right)
    {
        return (*func)(left->value, right->value);
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    SegTree st = SegTree(arr, [](segtype a, segtype b)
                         { return a + b; });
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            st.set(b, c);
        else
            cout << st.get(b, c) << endl;
    }
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
