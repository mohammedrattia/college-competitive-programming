#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <iomanip>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

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

struct Query
{
    ll v, k, idx;
    bool operator<(Query other)
    {
        if (v == other.v)
            return k > other.k;
        return v < other.v;
    }
};

bool comp(Query a, Query b)
{
    return a.v < b.v;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, q;
    cin >> n;
    cin >> q;
    vi colors(n), vis(n), answers(q);
    vector<vi> adj(n);
    // vector<vi> freq(n);
    rep(i, 0, n) cin >> colors[i];
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> qu;
    stack<int> post;
    qu.push(0);
    vis[0] = 1;
    while (!qu.empty())
    {
        int cur = qu.top();
        qu.pop();
        post.push(cur);
        vi::iterator parent = adj[cur].end();
        for (auto it = adj[cur].begin(); it != adj[cur].end(); it++)
        {

            if (!vis[*it])
            {
                qu.push(*it);
                vis[*it] = 1;
            }
            else
                parent = it;
        }
        if (parent != adj[cur].end())
            adj[cur].erase(parent);
    }

    vector<Query> queries(q);
    rep(i, 0, q)
    {
        cin >> queries[i].v >> queries[i].k;
        queries[i].v--;
        queries[i].idx = i;
    }
    sort(all(queries));

    stack<pair<map<int, int>, map<int, int>>> st;
    while (!post.empty())
    {
        int cur = post.top();
        post.pop();
        map<int, int> freq;
        map<int, int> fof;
        rep(i, 0, adj[cur].size())
        {
            if (st.top().first.size() > freq.size())
            {
                swap(freq, st.top().first);
                swap(fof, st.top().second);
            }
            for (auto &e : st.top().first)
            {
                int old = freq[e.F];
                if (old > 0)
                {
                    fof[old]--;
                    if (fof[old] == 0)
                        fof.erase(old);
                }
                freq[e.F] += e.S;
                fof[freq[e.F]]++;
            }
            st.pop();
        }
        int old = freq[colors[cur]];
        if (old > 0)
        {
            fof[old]--;
            if (fof[old] == 0)
                fof.erase(old);
        }
        freq[colors[cur]]++;
        fof[freq[colors[cur]]]++;

        int cnt = 0;
        auto it1 = lower_bound(all(queries), (Query){cur, INF, 0}, comp);
        auto it2 = lower_bound(all(queries), (Query){cur + 1, INF, 0}, comp);
        auto fof_it = fof.end();
        for (auto it = it1; it < it2; it++)
        {
            while (fof_it != fof.begin())
            {
                auto prev_it = prev(fof_it);
                if (prev_it->F >= it->k)
                {
                    fof_it = prev_it;
                    cnt += fof_it->S;
                }
                else
                {
                    break;
                }
            }
            answers[it->idx] = cnt;
        }
        st.push({move(freq), move(fof)});
    }
    rep(i, 0, q) cout << answers[i] << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
