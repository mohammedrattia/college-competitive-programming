#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
ll mod = 1e9+7;
ll add(ll a, ll b) {
    a%= mod;
    b %= mod;
    ll r = a+b;
    if (r >= mod) r -= mod;
    return r;
}
ll sub (ll a, ll b) {
    a%= mod;
    b %= mod;
    ll r = a-b;
    if (r < 0) r += mod;
    return r;
}
ll mul (ll a , ll b , ll  m = mod) {
    a %= m;
    b %= m;
    return (ll)((__int128)a*b % m);
}
ll power_mod(ll a , ll p, ll m = mod) {
    ll res = 1;
    a%= m;
    if (a < 0) a += m;
    while (p) {
        if (p&1) {
            res = mul(res,a,m);
        }
        a = mul(a,a,m);
        p >>=1;
    }
    return res;
}
ll inv (ll a) {
    return power_mod(a,mod-2,mod);
}
vector<int> fact,inv_fact;
void pre(int n) {
    fact.assign(n+1,1);
    inv_fact.assign(n+1,1);
    for (int i = 1; i <= n;i++) {
        fact[i] =mul(fact[i-1],i);
    }
    inv_fact[n] = inv(fact[n]);
    for (int i = n-1; i >= 0; i--) {
        inv_fact[i] = mul(inv_fact[i+1],(i+1));
    }
}
ll nCr(int n , int r) {
    if (r < 0 || r > n || n <= 0) return 0;
    return mul(mul(fact[n] ,inv_fact[r]),inv_fact[n-r]);
}
void solve() {
#define int ll
    int n , k ;cin >> n >> k;
    if (k &1) {
        cout << 0 << endl;
        return;
    }
    int cnt = n/k;
    int m = n%k;
    int ans = power_mod(2,nCr(k,k/2));
    int u = 0;
    for (int i= 1; i <= k; i++) {
        int v = nCr(k-1,k/2-1);
        if (v)v = power_mod(2,nCr(k-1,k/2-1));
        ans = sub(ans,v);
        int z= cnt - 1 + (m >= i);
        z = power_mod(2,z);

        // v = mul(v,2);
        ans = add(ans,mul(v,z));

    }
    cout << ans << endl;
#undef int
}

void solve_I() {
    ll n; cin >> n;
    vector<ll> arr(n), diff(n/2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n <= 1) return void (cout << -1 << endl);
    ll cnt = 0;
    for (int i = 0; i < n/2; i++) {
        diff[i] = abs(arr[i] - arr[n-i-1]);
        cnt += diff[i] == 0;
    }
    if (cnt == n/2) return void (cout << -1 << endl);
    ll ans = diff[0];
    for (int i = 1; i < n/2; i++) {
        ans = gcd(ans, diff[i]);
    }
    cout << ans << endl;
}
struct Node {
    int val = 0;
};
struct segmentTree {
#define L (2*node+1)
#define R (2*node+2)
#define mid ((l+r)/2)
private:
    int n, sz;
    vector<Node> seg;
    Node base;
    Node merge(const Node&a , const Node& b) {
        Node ret;
        ret.val = a.val + b.val;
        return ret;
    }
    void build(int l , int r, int node, vector<int>& arr) {
        if (l >= n) return;
        if (l == r) {
            seg[node].val = arr[l];
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node] = merge(seg[L],seg[R]);
    }
    Node querySeg(int l , int r, int node, int lq, int rq) {
        if (l > rq || r < lq) return base;
        if (l >= lq && r <= rq) return seg[node];
        Node left = querySeg(l,mid,L,lq,rq);
        Node right = querySeg(mid+1,r,R,lq,rq);
        return merge(left,right);
    }

public:
    segmentTree (vector<int>&arr) {
        n = arr.size();
        sz = 1;
        while (sz <  n) sz<<=1;
        seg.assign(sz*2,base);
        build(0,sz-1,0,arr);
    }
    Node query(int l , int r) {
        return querySeg(0,sz-1,0,l,r);
    }
};
void solve_f() {
    int n,q; cin >> n >> q;
    vector<int> a(n),b(n);
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        int l, r ; cin >> l >> r;

    }
#undef mid
#undef L
#undef R
}
void solve_c() {
#define int ll
    int n ,k,x; cin >> n >> k >> x;
    vector<int> num(n);
    for (auto &el : num) cin >> el;
    int l = 0, r = INF,ans = -1;
    auto valid = [&](int cur) {
        int cnt = 0;
        for (int i = 0; i <n;i++) {
            int lvl = num[i]/x;
            if (lvl <= cur)cnt += (cur-lvl+1);
        }
        return cnt <= k;
    };

    while (l <= r) {
        int mid = l + (r-l)/2;
        if (valid(mid)) {
            l = mid+1;
            ans = mid;
        }else {
            r = mid-1;
        }
    }
    vector<int> a(n, 0);
    if (ans != -1) {
        int s = 0;
        for (int i = 0; i < n;i++) {
            int lvl = num[i]/x;
            if (lvl > ans) continue;
            a[i] = (ans-lvl+1);
            s += a[i];
            num[i] += (a[i]*x);
        }
        k -= s;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i = 0; i < n;i++) {
        pq.push({num[i],i});
    }
    while (pq.size() && k) {
        auto [el,idx] = pq.top();
        pq.pop();
        assert(k >= 0);
        a[idx]++;
        k--;
        pq.push({el+x,idx});
    }
    for (auto el : a) cout << el << ' ';
    cout << endl;
#undef int
}

void H() {
    int n, m; cin >> n >> m;
    vector<int> state(n + 1);
    int t = 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        if (state[v] == 0 && state[u]) {
           state[v] = t++;
            cout << 0;
        } else if (state[v] == 0 && state[u] == 0) {
            state[u] = t++, state[v] = t ++;
            cout << 0;
        } else if (state[u] && state[v]) {
            // cout << state[u] << ' ' << state[v] << '\n';
            if (state[u] > state[v]) cout << 1;
            else cout  << 0;
        } else {
            state[u] = t++;
            cout << 0;
        }
    }
}

signed main()
{
    cin.tie(nullptr); cout.tie(nullptr);
    // solve_I();
    // pre(1e5+1);
    // int t ;cin >> t;while (t--)
    solve_c();
    // H();
}