#include <bits/stdtr1c++.h>

using namespace std;

int n, m;
unordered_map<int, int> mem;

int dp(int i)
{
  if (i == m)
  {
    return 1;
  }
  if (i % 3 != 0 || i <= 0)
  {
    return 0;
  }
  if (mem.count(i))
    return mem[i];

  return mem[i] = max(dp(i/3), dp(i/3 * 2));
}

void solve()
{
  cin >> n >> m;
  mem.clear();
  if (n < m)
  {
    cout << "NO" << endl;
    return;
  }
  if (dp(n))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}