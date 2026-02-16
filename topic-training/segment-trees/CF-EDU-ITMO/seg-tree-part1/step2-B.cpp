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
    ll cnt;
    ll leafs;
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
    const segtype NEUTRAL_CASE = {0};
    Tree tree;
    ll sz;
    segtype (*merge)(segtype a, segtype b);

    SegTree(vector<ll> &arr, segtype (*operation)(segtype a, segtype b))
    {
        merge = operation;
        sz = arr.size();
        tree.head = buildTree(&arr, 0, arr.size());
    }

    void set(int i)
    {
        setRec(i, tree.head, 0, sz);
    }

    ll get(int i)
    {
        return getRec(i, tree.head, 0, sz);
    }

private:
    TreeNode *buildTree(vector<ll> *arr, int l, int r)
    {
        if (r - l == 1)
        {
            TreeNode *leaf = new TreeNode();
            leaf->item = single((*arr)[l]);
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
        root->item = merge(left->item, right->item);
        return root;
    }

    ll getRec(int &i, TreeNode *x, int lx, int rx)
    {
        if (x == NULL || i == -1)
        {
            return 0;
        }
        if (x->item.cnt <= i || (rx - lx == 1 && i == 0))
        {
            i -= x->item.cnt;
            return x->item.leafs;
        }
        int m = (lx + rx) / 2;
        ll s1 = getRec(i, x->left, lx, m);
        ll s2 = getRec(i, x->right, m, rx);
        return s1 + s2;
    }

    void setRec(int i, TreeNode *x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            x->item = single(!x->item.cnt);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            setRec(i, x->left, lx, m);
        else
            setRec(i, x->right, m, rx);
        x->item = merge(x->left->item, x->right->item);
    }

    segtype single(ll v)
    {
        return {v, 1};
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
    SegTree st = SegTree(arr, [](segtype a, segtype b) -> segtype
                         { return {a.cnt + b.cnt, a.leafs + b.leafs}; });

    rep(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 1)
            st.set(b);
        else
            cout << st.get(b) - 1 << endl;
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
