#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define F first
#define S second
#define pr pair<long long, long long>
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<ll> q;
    rep(i, 0, n)
    {
        if (str[i]=='1') continue;
        q.push_back(i);
    }

    ll arr[n];
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll pre[n+1] = {0};
    rep(i, 1, n+1)
    {
        pre[i] = pre[i-1] + arr[i-1];
    }

    ll idx = -1;
    rep(i, 0, n)
    {
        if (str[i]=='1') continue;
        else
        {
            idx = i;
            break;
        }
    }

    ll cur = sum;
    ll l = 0, r = n-1;
    if (idx != -1){
        while(r > l)
        {
            if ((arr[l] <= arr[r] || r == idx) && l < idx)
            {
                cur -= arr[l];
                l += 1;
            }
            else if (r > idx)
            {
                cur -= arr[r];
                r -= 1;
            }
            sum = max(sum, cur);
        }
        arr[idx] = k - sum;
        str[idx] = '1';
        rep(i, 0, n)
        {
            if (str[i]=='1') continue;
            
            arr[i] = -1e18;
        }
    }


    ll ans = -1e18;
    ll qcur;
    rep(i, 0, q.size()+1)
    {
        if (q.size() == 0)
        {
            qcur = sum;
            l = 0, r = n-1;
        }
        else if (i == 0)
        {
            qcur = pre[q[i]];
            l = 0, r = q[i]-1;
        }
        else if (i == q.size())
        {
            qcur = pre[q[i]]-pre[q[i-1]];
            l = q[i-1]+1, r = n-1;
        }
        else
        {
            qcur = pre[q[i]]-pre[q[i-1]];
            l = q[i-1]+1, r = q[i]-1;
        }
        while(r > l)
        {
            if (arr[l] <= arr[r])
            {
                qcur -= arr[l];
                l += 1;
            }
            else
            {
                qcur -= arr[r];
                r -= 1;
            }
            ans = max(ans, qcur);
        }
    }
    if (ans > k || (ans != k && (int)q.size() == 0))
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    rep(i, 0, n)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
