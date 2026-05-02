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
 * i can get any element  ((n-1)/2) to 0 and n
 * every adding is either to  your place or the next mex
 */

void solve() {
    int n ;  cin>> n;
    int m; cin >> m;
    int tmp = m;
    int cnt = 0;
    string str; cin >> str;
    for (auto i : str) cnt += (i == 'O');
    int l = 0, r= min(cnt,m), ans =-1;
    auto valid = [&](int take){
        bool flag = false;
        auto tmp = str;
        int k = take;
        for (int i= n-1; i>= 0; i--){
            if (tmp[i] == 'O') {
                k --;
                tmp[i] = '!';
            }
            if (k == 0) break;
        }
        int cap = m;
        int cnt1 = 0;
        for (int i= 0; i < n;i++){
            if (tmp[i] == 'W' && cnt1 < cap) cnt1++;
            if (tmp[i] == '!'){
                cap--;
                while (cnt1 > cap) cnt1--;
            }
            if (tmp[i] == 'T') {
                if (cnt1 == 0) return false;
                cnt1--;
            }
        }
        return true;
    };
    while (l <= r){
        int mid = (r + l)/2;
        if (valid (mid)){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}


signed main(void)
{
    ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    cout << setprecision(10) << fixed;
    int t;cin >> t;while(t--)
    solve();
    return 0;
}