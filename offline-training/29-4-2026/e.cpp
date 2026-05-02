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
* 
*/

#define int long long
void solve() {
    int n; cin >> n;
    vector<int> val(n);
    for (auto &i : val) cin >> i;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n;i++){
        int x ,y; cin >> x >> y;
        --x,--y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    min_heap<array<int,2>> pq;
    int sum = 0;
    vector<int> ava(n);
    for (int i = 0; i < n;i++){
        sum += val[i];
        if (adj[i].size() == 1){
            pq.push({val[i],adj[i][0]});
        }
        ava[i] = adj[i].size();
    }
    int c = n;
    vector<pair<int,int>> ans;
    ans.reserve(n-1);
    
    
}


signed main(void)
{
    ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    cout << setprecision(10) << fixed;
    int t;cin >> t;
    while(t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}