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
#define baseCase (segtype)0;
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
class SegmentTree
{
public:
    Tree tree;

    SegmentTree(vector<segtype> &arr)
    {
        tree.head = buildTree(&arr, 0, arr.size());
    }
    void set(int i, segtype v, TreeNode *x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            x->value = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i <= m)
            set(i, v, x->left, lx, m);
        else
            set(i, v, x->right, m + 1, rx);
        x->value = op(x->left, x->right);
    }
    segtype sum(int l, int r, TreeNode *x, int lx, int rx)
    {
        if (l >= rx || lx >= r || x == NULL)
            return baseCase;
        if (lx >= l && rx <= r)
            return x->value;
        int m = (lx + rx) / 2;
        segtype s1 = sum(l, r, x->left, lx, m);
        segtype s2 = sum(l, r, x->right, m, rx);
        return op(s1, s2);
    }

private:
    TreeNode *linkTwoSubtrees(TreeNode *left, TreeNode *right)
    {
        TreeNode *root = new TreeNode();
        root->left = left;
        root->right = right;
        root->value = op(left, right);
        return root;
    }
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
        TreeNode *root = linkTwoSubtrees(left, right);
        return root;
    }
    segtype op(TreeNode *left, TreeNode *right)
    {
        return op(left->value, right->value);
    }
    segtype op(segtype a, segtype b)
    {
        return a + b;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    SegmentTree st = SegmentTree(arr);
    rep(i, 0, n)
    {
        cout << st.sum(i, i + 5, st.tree.head, 0, n) << endl;
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
