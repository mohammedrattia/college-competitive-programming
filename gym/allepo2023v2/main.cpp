#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (x == 1) {
        cout << 1 << endl;
        return;
    }
    ll cnt = 0;
    while (x != 1) {
        ll mx = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == -1) continue;
            ll val = gcd(arr[i], x);
            if (val > mx) {
                mx = val;
                idx = i;
            }
        }
        if (idx == -1) {
            cout << -1 << endl;
            return;
        }
        x /= mx;
        arr[idx] = -1;
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
