    //     ____  __.                                         .__                   _____                                      .___
    //    |    |/ _|____   ____ ______     _____   _______  _|__| ____    ____   _/ ____\_____________  _  _______ _______  __| _/
    //    |      <_/ __ \_/ __ \\____ \   /     \ /  _ \  \/ /  |/    \  / ___\  \   __\/  _ \_  __ \ \/ \/ /\__  \\_  __ \/ __ |
    //    |    |  \  ___/\  ___/|  |_> > |  Y Y  (  <_> )   /|  |   |  \/ /_/  >  |  | (  <_> )  | \/\     /  / __ \|  | \/ /_/ |
    //    |____|__ \___  >\___  >   __/  |__|_|  /\____/ \_/ |__|___|  /\___  /   |__|  \____/|__|    \/\_/  (____  /__|  \____ |
    //            \/   \/     \/|__|           \/                    \//_____/                                    \/           \/
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ld = double;
    const int INF = 1e9;
    const int mod = 1e9+7;
    template <typename U>
    using min_heap = priority_queue<U, vector<U>, greater<U>>;


    // write your thoughts here before submitting
    /*
    * for every node i am either taking the node or taking the sum of the nodes down this ndoe
    * 
    */
    struct Node{
        int val;
        int st;
        bool lazy;
        int prp;
        Node(){
            val = 0;
            st = 0;
            lazy = 0;
            prp = 0;
        };
        // don't forget to set the base
        Node(int a){

        }
    };
    struct segmentTree{
    #define L (2 * node + 1)
    #define R (2 * node + 2)
    #define mid ((l + r) / 2)
    private:
        // don't forget to set the apply function and the base node
        // base node must be something won't effect your segment
        int n , sz;
        vector<Node> seg;
        Node base;
        Node merge(const Node &a , const Node& b){
            Node ret;
            ret.val = a.val + b.val;
            // ret.st = max(a.st, b.st);
            return ret;
        }
        void build(int l, int r, int node, vector<int> &arr) {
            if (l >=n) return;
            if (l == r) {
                seg[node].val = arr[l];
                return;
            }
            build(l, mid, L, arr);
            build(mid + 1, r, R, arr);
            seg[node] = merge(seg[L],seg[R]);
        }
        void build (int l , int r , int node){
            if (l == r){
                seg[node].val = 0;
                return;
            }
            build(l,mid,L);
            build(mid+1,r,R);
            seg[node] = merge(seg[L],seg[R]);
        }
        Node querySeg(int l, int r, int node, int lq, int rq){
            if (seg[node].lazy) apply(l,r,node);
            if (l > rq || r < lq) return base;
            if (l >= lq && r <= rq) return seg[node];
            Node left = querySeg(l, mid, L, lq, rq);
            Node right = querySeg(mid + 1, r, R, lq, rq);
            return merge(left,right);
        }
        void apply(int l , int r, int node){
            if (!seg[node].lazy) return;

            if (l != r){
                seg[L].lazy = seg[R].lazy = true;
                seg[L].prp = seg[R].prp = seg[node].prp;
            }
            seg[node].st = seg[node].prp;
            if (seg[node].st ==  -1) seg[node].val = 0;
            if (seg[node].st == 1) seg[node].val = 1;
            seg[node].lazy = false;
            seg[node].prp = 0;
        }
        void updateSeg(int l , int r, int node , int lq ,int rq, int val){
            if (seg[node].lazy) apply(l,r,node);
            if (l > rq || r < lq) return;
            if (l >= lq && r <= rq){
                seg[node].lazy = true;
                seg[node].prp = val;
                apply(l,r,node);
                return;
            }
            // left
            updateSeg(l,mid,L,lq,rq,val);
            // right
            updateSeg(mid+1,r,R,lq,rq,val);
            seg[node] = merge(seg[L],seg[R]);
        }
    public:
        segmentTree(vector<int>& arr){
            n = arr.size();
            sz = 1;
            while (sz < n) sz<<=1;
            seg.assign(sz*2,base);
            build(0,sz-1,0,arr);
        }
        segmentTree(int _n){
            n = _n;
            sz = 1;
            while (sz < n) sz<<=1;
            seg.assign(sz*2,base);
            build(0,sz-1,0);
        }
        Node query (int idx){
            return query(idx,idx);
        }
        Node query(int l , int r){
            return querySeg(0,sz-1,0,l,r);
        }
        void update(int idx,int val){
            update(idx,idx,val);
        }
        void update(int l , int r,int val){
            updateSeg(0,sz-1,0,l,r,val);
        }
    #undef L
    #undef R
    #undef mid
    };

    void solve() {
        int n , q; cin >> n >> q;
        vector<int> adj[n+1];
        vector<bool> par(n+1);
        for (int i = 1; i < n;i++){
            int x; cin >> x;
            --x;
            par[i] = true;
            // adj[i].push_back(x);
            adj[x].push_back(i);
        }
        vector<bool>vis(n+1);

        int timer = -1;
        vector<int> flat,in(n),out(n);
        flat.reserve(n+1);
        function<void(int,int)> build = [&](int node, int par){
            in[node] = ++timer;
            flat.push_back(0);

            for (auto ch : adj[node]){
                if (ch == par) continue;
                build(ch,node);
            }
            out[node] = timer;
        };
        for (int i = 0; i < n;i++){
            if (par[i]) continue;
            build(i,-1);
        }
        segmentTree tri(n);
        while (q--){
            int x; cin >> x;
            --x;
            int l = in[x], r= out[x];
            auto tmp = tri.query(l,l);
            if (tmp.st == -1){
                cout << tri.query(0,flat.size()-1).val << endl;
                continue;
            }
            else{
                tri.update(l,r,-1);
                tri.update(l,l,1);
                cout << tri.query(0,flat.size()-1).val << endl;
            }
        }
    }


    signed main(void)
    {
        ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
        cout << setprecision(10) << fixed;
        int t;cin >> t;while(t--)
        solve();
        return 0;
    }